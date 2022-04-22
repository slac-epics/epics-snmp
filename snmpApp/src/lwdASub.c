 /* Collection of aSub subroutines...*/
 /*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <dbDefs.h>
#include <alarm.h>
#include <registryFunction.h>
#include <aSubRecord.h>
#include <epicsExport.h>
#include <math.h>
#include <stdlib.h>


static long asub_bw(aSubRecord *pr){
/*------------------------------------------------------------------------------
 * Calculate net bandwidth from snmp IF counters
 * IF counters seem to update at 5-10 second rate
 * We are using 32-bit counters, so need to account for rollover
 * Assume a two-element waveform of sequential counter values as input
 * Output is bandwidth in MBits
 * Overhead factor accounts for frame size and whatever else leads to overestimation of bandwidth
 *----------------------------------------------------------------------------*/
    double *counters = (double*)pr->a;
    double *delta_t = (double*)pr->b;
    double *bw = (double*)pr->vala;
    
    double val1 = counters[1];
    double val0 = counters[0];
    double overhead = 0.357;

    if ((val1 == val0) || (val1 == 0 || val0 == 0)) return -1;

    // Check for rollover and fix if needed
    if (val1 < val0) {
        val1 += pow(2.0, 32.0);
    }

    *bw = ((val1 - val0)/(*delta_t))*8.0*1.0E-6*overhead;
    
    //printf("val0=%f, val1=%f, bw=%f\n", val0, val1, *bw);

    return 0;
}

/**************************************************************************/

epicsRegisterFunction(asub_bw);


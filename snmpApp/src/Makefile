TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#========================================
USR_CFLAGS += -I/usr/include
USR_CFLAGS += -I/usr/lib64
USR_CFLAGS += `$(NETSNMP_TOP)/$(PKG_ARCH)/bin/net-snmp-config --cflags`
USR_CFLAGS += -DNETSNMP_NO_INLINE

#USR_LDFLAGS += `net-snmp-config --libs`
#PROD_LDLIBS += `net-snmp-config --libs`


USR_INCLUDES += -I$(NETSNMP_INCLUDE)
netsnmp_DIR = $(NETSNMP_LIB)
USR_LIBS_Linux += netsnmp
USR_CFLAGS += $(shell $(PERL) ../getNetSNMPversion.pl $(NETSNMP_TOP)/$(PKG_ARCH)/bin)
USR_CPPFLAGS += $(shell $(PERL) ../getNetSNMPversion.pl $(NETSNMP_TOP)/$(PKG_ARCH)/bin)

#========================================
# Build an IOC support library
LIBRARY_IOC += devSnmp

# Install dbd files
DBD += devSnmp.dbd
DBD += lwdASubSupport.dbd

# The following are compiled and added to the Support library
devSnmp_SRCS += snmpRegister.cpp
devSnmp_SRCS += snmpSessShow.c
devSnmp_SRCS += devSnmp.cpp
devSnmp_LIBS += $(EPICS_BASE_IOC_LIBS)

#========================================
# uild an ioc application
PROD_IOC = snmp

# snmp.dbd will be created and installed
DBD += snmp.dbd

# snmp.dbd will be made up from these files:
snmp_DBD += base.dbd
snmp_DBD += devSnmp.dbd
snmp_DBD += lwdASubSupport.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
snmp_SRCS += snmp_registerRecordDeviceDriver.cpp
snmp_SRCS_DEFAULT += snmpMain.cpp
snmp_SRCS_vxWorks += -nil-

snmp_SRCS += snmpRegister.cpp
snmp_SRCS += snmpSessShow.c
snmp_SRCS += devSnmp.cpp
snmp_SRCS += lwdASub.c

# The following adds support from base/src/vxWorks
snmp_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Add all the support libraries needed by this IOC
snmp_LIBS += devSnmp

# NOTE: To build SNL programs, SNCSEQ must be defined
# in the <top>/configure/RELEASE file
ifneq ($(SNCSEQ),)
    # This builds sncExample as a component of snmp
    snmp_SNCFLAGS += +r
    snmp_DBD += sncExample.dbd
    snmp_SRCS += sncExample.stt
    snmp_LIBS += seq pv

    # The following builds sncProgram as a standalone application
    PROD_HOST += sncProgram
    sncProgram_SNCFLAGS += +m
    sncProgram_SRCS += sncProgram.st
    sncProgram_LIBS += seq pv
    sncProgram_LIBS += $(EPICS_BASE_HOST_LIBS)
endif

snmp_SYS_LIBS += netsnmp
snmp_LIBS     += $(EPICS_BASE_IOC_LIBS)

#========================================
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
#
# End of file


TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#========================================
ifdef PKG_ARCH
USR_CFLAGS_Linux += $(shell $(NETSNMP_BIN)/net-snmp-config --cflags)
USR_CFLAGS_Linux += -DNETSNMP_NO_INLINE
USR_CFLAGS_Linux += $(shell $(PERL) ../getNetSNMPversion.pl $(NETSNMP_BIN))
USR_CFLAGS_Linux := $(filter-out -Wstrict-prototypes,$(USR_CFLAGS_Linux))
USR_CFLAGS_Linux := $(filter-out -Wno-format-truncation,$(USR_CFLAGS_Linux))
USR_CFLAGS_Linux := $(filter-out -Wundef,$(USR_CFLAGS_Linux))
USR_CPPFLAGS_Linux += $(shell $(PERL) ../getNetSNMPversion.pl $(NETSNMP_BIN))
endif

USR_INCLUDES += -I$(NETSNMP_INCLUDE)
netsnmp_DIR = $(NETSNMP_LIB)
USR_LIBS_Linux += netsnmp

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


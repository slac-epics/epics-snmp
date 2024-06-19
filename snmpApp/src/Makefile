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

# The following are compiled and added to the Support library
devSnmp_SRCS += snmpRegister.cpp
devSnmp_SRCS += snmpSessShow.c
devSnmp_SRCS += devSnmp.cpp
devSnmp_LIBS += $(EPICS_BASE_IOC_LIBS)

#========================================
# Build an ioc application
PROD_IOC = snmp

# snmp.dbd will be created and installed
DBD += snmp.dbd

# snmp.dbd will be made up from these files:
snmp_DBD += base.dbd
snmp_DBD += devSnmp.dbd

# <name>_registerRecordDeviceDriver.cpp will be created from <name>.dbd
snmp_SRCS += snmp_registerRecordDeviceDriver.cpp
snmp_SRCS_DEFAULT += snmpMain.cpp

# Add all the support libraries needed by this IOC
snmp_LIBS += devSnmp

snmp_LIBS += $(EPICS_BASE_IOC_LIBS)

#========================================
include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE
#
# End of file


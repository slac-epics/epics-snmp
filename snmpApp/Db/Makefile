TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#----------------------------------------------------
#  Optimization of db files using dbst (DEFAULT: NO)
#DB_OPT = YES

#----------------------------------------------------
# Create and install (or just install) into <top>/db
# databases, templates, substitutions like this

# Wiener crates
DB += crat_wiener_snmp.db
DB += crat_wiener_snmp_test.db

# Generic snmp
DB += snmp.db
DB += snmp_ai.template
DB += snmp_bi.template
DB += snmp_bo.template
DB += snmp_lo.template
DB += snmp_li.template
DB += snmp_mbbo.template
DB += snmp_mbbi.template
DB += snmp_so.template
DB += snmp_si.template
DB += snmp_wf.template
DB += misc_common.template

# Wiener Crates
DB += crat_loc.template
DB += crat_slot.template
DB += crat_wiener_snmp.template

# Dell iDRAC server i
DB += dell_idrac_li.template
DB += dell_idrac_li_convert.template
DB += dell_idrac_mbbi_status.template
DB += dell_idrac_si.template
DB += dell_idrac_wf.template

# Geist Watchdog temp/humidity
DB += watchdog_100.db

# APC PDUs
DB += apc_pdu_common.db
DB += apc_pdu_outlet.db
DB += apc_pdu_8x.db

# APC PDUs
DB += apc_pdu_common.db
DB += apc_pdu_outlet.db
DB += apc_pdu_8x.db

# Tripp-Lite PDUs
DB += trippLite_pdu_common.db
DB += trippLite_pdu_outlet.db
DB += trippLite_pdu_2x.db
DB += booster_fan_control.db
DB += spear_fan_control.db

# Examples
#DB += snmp_linux.db
#DB += crat.db
#DB += crat_test.db
#DB += crat_loc_test.template
#DB += crat_wiener_snmp_test.template
#DB += crate_slot_test.template
#DB += snmp_ping.db

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE


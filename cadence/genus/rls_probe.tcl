if {![info exists ::env(AQUILA_REPO_ROOT)] ||
    ![info exists ::env(AQUILA_FS120_ROOT)] ||
    ![info exists ::env(AQUILA_SDC)]} { error "Aquila environment is incomplete" }
set repo $::env(AQUILA_REPO_ROOT)
set fs120 $::env(AQUILA_FS120_ROOT)
set sdc $::env(AQUILA_SDC)
set_db init_lib_search_path [list "$fs120/liberty/lib_flow_ss" "$fs120/verilog"]
set_db init_hdl_search_path [list "$repo/rtl" "$repo/cadence/genus"]
read_libs "$fs120/liberty/lib_flow_ss/tsl18fs120_scl_ss.lib"
read_hdl -language sv "$repo/rtl/rls_engine.v" "$repo/cadence/genus/rls_probe_top.v"
elaborate rls_probe_top
check_design -unresolved > "$repo/cadence/genus/rls_probe_check_design.rpt"
read_sdc $sdc
set_db syn_generic_effort low
set_db syn_map_effort low
syn_generic
report_area > "$repo/cadence/genus/rls_probe_generic_area.rpt"
syn_map
report_area > "$repo/cadence/genus/rls_probe_mapped_area.rpt"
syn_opt
report_timing -max_paths 20 > "$repo/cadence/genus/rls_probe_timing.rpt"
write_hdl -mapped > "$repo/cadence/rls_probe_netlist.v"
puts "AQUILA_RLS_PROBE_COMPLETE"

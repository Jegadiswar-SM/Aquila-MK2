# Aquila C2S qualification-only Genus flow.
# Technology paths are supplied by the invoking environment; no PDK files are
# copied or modified. This is not a signoff synthesis script.

if {![info exists ::env(AQUILA_REPO_ROOT)]} {
  error "AQUILA_REPO_ROOT is required"
}
if {![info exists ::env(AQUILA_FS120_ROOT)]} {
  error "AQUILA_FS120_ROOT is required"
}
if {![info exists ::env(AQUILA_SDC)]} {
  error "AQUILA_SDC is required"
}

set repo $::env(AQUILA_REPO_ROOT)
set fs120 $::env(AQUILA_FS120_ROOT)
set sdc $::env(AQUILA_SDC)
set filelist "$repo/cadence/genus/qualify_asic_filelist.f"
set ss_lib "$fs120/liberty/lib_flow_ss/tsl18fs120_scl_ss.lib"

set_db init_lib_search_path [list "$fs120/liberty/lib_flow_ss" "$fs120/verilog"]
set_db init_hdl_search_path [list "$repo/rtl" "$repo/rtl/asic"]
read_libs $ss_lib
read_hdl -language sv -f $filelist
elaborate aquila_scl180_top
check_design -unresolved > "$repo/cadence/genus/qualify_check_design.rpt"
check_timing -verbose > "$repo/cadence/genus/qualify_check_timing.rpt"
read_sdc $sdc
report_clocks > "$repo/cadence/genus/qualify_clocks.rpt"
report_timing -max_paths 20 > "$repo/cadence/genus/qualify_pre_synth_timing.rpt"
report_area > "$repo/cadence/genus/qualify_pre_synth_area.rpt"
set_db syn_generic_effort low
set_db syn_map_effort low
syn_generic
report_area > "$repo/cadence/genus/qualify_generic_area.rpt"
syn_map
report_area > "$repo/cadence/genus/qualify_mapped_area.rpt"
syn_opt
report_timing -max_paths 20 > "$repo/cadence/qualify_post_synth_timing.rpt"
report_area > "$repo/cadence/qualify_post_synth_area.rpt"
write_hdl -mapped > "$repo/cadence/qualify_aquila_synth.v"
write_sdc > "$repo/cadence/qualify_aquila_synth.sdc"
puts "AQUILA_GENUS_SYNTHESIS_COMPLETE"

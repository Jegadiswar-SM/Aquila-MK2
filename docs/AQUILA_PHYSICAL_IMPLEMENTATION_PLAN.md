# Aquila physical implementation plan

Status: **prepared; not executable with current evidence.** No coordinates,
utilization, macro dimensions, power widths, or skew targets are invented.

## Gate to enter Innovus

Require an elaborated/synthesized netlist, approved DFT netlist, real standard
cell LEF/GDS/Liberty/CDL, real SRAM LEF/GDS/Liberty/CDL, real IO/pad/corner/fill
collateral, tech LEF/routing rules, approved MMMC, package/pad plan, and power
intent. The current PDK tree has zero LEF/GDS/CDL and no SRAM/IO payload.

## Ordered plan

1. Establish the selected SCL180 metal variant from C2S rules.
2. Build the pad-integrated top and verify pad/power/ground/test connectivity.
3. Place SRAM macros first; choose orientation and banking from actual macro
   dimensions and bus topology.
4. Define core boundary, utilization, macro halos/channels, IO placement, and
   power ring/strap topology from real rules.
5. Place standard cells and assess congestion around the 256-bit SRAM bus,
   time-multiplexed MLP datapath, control interface, and DFT.
6. Run CTS only after clock definition, placement, CTS cells, and MMMC are
   valid; check skew, insertion delay, transition, pulse width, and gating.
7. Route with actual technology rules, antenna repair, filler/tap/endcap,
   tie, decap, and density methodology.
8. Extract with the selected Quantus/Calibre-compatible RC flow and feed SPEF
   to Tempus; run setup/hold and electrical checks in all required modes.
9. Run qualified power, static/dynamic IR, EM, antenna, DRC, LVS, ERC/density,
   and final equivalence/GLS.
10. Generate GDS only after all gates pass and create a final manifest.

The PDK exposes Calibre runset families for 4/5/6 metal and L/T/T3 options,
but that is not a project selection. `6M1L` and any numerical grid are
therefore C2S decisions, not defaults.

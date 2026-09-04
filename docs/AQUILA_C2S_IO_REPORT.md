# AQUILA-MK1 — C2S IO/Pad Report

## Result

**IO/PAD DECISION = CANDIDATE SET FOUND; CHIP BINDING STILL BLOCKED.** The
staging tree contains CIO150/CIO250 and PIO520SL families with real 6M1L
physical views. CIO150/CIO250 have max/min Liberty, LEF, GDS, and CDL;
PIO520SL has LEF/GDS/CDL but no Liberty. Digital Verilog pad models were not
found in the inspected IO trees.

The only Aquila-local pad implementation is `rtl/mhda_io_ring.v`, which
instantiates `sky130_fd_io__*` cells and is explicitly excluded from SCL180.
`rtl/asic/aquila_scl180_top.v` is a technology-neutral pass-through boundary;
it is not a real pad binding.

Exact candidate payload roots are:

```text
/home/24bvd1009/pdk-backup-staging/scl180/io/cio150/6M1L/
/home/24bvd1009/pdk-backup-staging/scl180/io/cio250/6M1L/
/home/24bvd1009/pdk-backup-staging/scl180/io/pio520/6M1L/
```

CIO150 and CIO250 contain 6M1L LEF/GDS/CDL and max/min Liberty/DB views in
the inspected staging tree. No digital Verilog pad models were found there.
PIO520SL contains physical LEF/GDS/CDL evidence but no verified Liberty or
Verilog model. This supports controlled candidate selection, not a complete
pad-ring signoff claim.

## Functional port scope

`rls_dnn_top` has 124 input bits and 62 output bits, 186 signal bits total,
excluding supply/pad duplication. The interface includes clock, active-low
reset, sample enable, 33-bit stream input, 18-bit stream output-side signals,
53 control inputs, 41 control outputs, weight programming, `clk_gate_en`, and
`irq_fault`. There are no RTL scan or MBIST pins.

## Decision

Use `aquila_scl180_top` for a pad-integrated deliverable, with only
`aquila_scl180_io_bind` replaced by verified SCL180 cells. Keep `rls_dnn_top`
as the core-only debug top. C2S must select CIO150 versus CIO250, confirm
cross-library electrical compatibility, provide simulation models or an
approved substitute, and supply package/pad-ring methodology. Package, pad
count, IO voltage, power/ground pad count, ESD, corner cells, seal ring, and
scan/test access remain **UNKNOWN — C2S EVIDENCE INSUFFICIENT**.

# REQUIRED FROM C2S

## PDK

- Confirm the actual root and supported Cadence setup for `ts18scl` v2.0.
- Make the implementation top explicit: `aquila_scl180_top` for a
  pad-integrated chip or `rls_dnn_top` for a core-only demonstrator. The
  current ASIC filelist contains both and does not select one.
- Provide verified digital standard-cell Liberty, LEF, GDS, CDL, and Verilog.
- Provide selected metal-stack tech LEF/tech files and routing/layer maps.
- Confirm rule-deck ownership/version and PVS versus Calibre methodology.

## SRAM

- Select a real macro or compiler output with depth ≥8192 and sufficient
  composed width for 256 bits.
- Provide Verilog, Liberty, LEF, GDS, CDL, supplies, test/repair pins,
  write-mask behavior, latency, and collision semantics.
- Confirm reset/power-up behavior and MBIST/repair support.

## IO and package

- Select input/output/clock/reset/power/ground/DFT pads, corner/filler cells,
  ESD/latch-up requirements, pad order, package, and pad count.
- Confirm IO voltage and core/IO/SRAM supply relationships.

## Standard cells and DFT

- Confirm scan cell/ICG/tie/tap/endcap/filler/decap/antenna collateral.
- Confirm Modus availability and required logic-scan, MBIST, ATPG, test-mode,
  scan-access, and coverage methodology.

## Cadence/tools

- Confirm executable paths and versions for Xcelium, Genus, Conformal,
  Modus, Innovus, Tempus, Quantus, Voltus, and PVS.
- Provide license availability and lab run wrappers without credentials.

## Libraries/MMMC/RC

- Provide approved functional/test MMMC modes and real PVT/RC views.
- Approve clock period, uncertainty, input/output delays, loads, and drives.
- Provide extraction tech and SPEF/Tempus integration procedure.

## Physical verification and power

- Provide DRC/LVS/ERC/antenna/density run commands, layer maps, macro CDL
  handling, power-net conventions, IR/EM limits, package assumptions, and
  Voltus methodology if available.

## Project approvals

- Approve 50 MHz interim recommendation or another clock requirement.
- Approve pad-integrated chip versus core-only deliverable and package.
- Approve weight-loading/initialization sequence and authoritative current-
  topology MLP checkpoint plus golden vectors.

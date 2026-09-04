# AQUILA-MK1 — C2S DFT Report

## Result

**DFT DECISION = BLOCKED.** A Modus installation tree exists at
`/home/install/MODUS221`, but `modus`, `modustest`, scan libraries, ATPG
collateral, SRAM test models, and MBIST metadata were not found in `PATH` or
the inspected PDK tree.

## Recommended minimum

Full scan of synthesizable logic flops, no compression unless the lab requires
it, one confirmed test mode, confirmed scan clock/enable/in/out access, and
stuck-at plus transition ATPG for any production-style claim. SRAM MBIST must
be implemented only if the selected macro is supported by the available Modus
flow. Logic scan and SRAM MBIST are separate requirements.

No scan chain count, coverage target, test clock, test pin assignment, MBIST
algorithm, repair support, or license status may be filled by assumption.

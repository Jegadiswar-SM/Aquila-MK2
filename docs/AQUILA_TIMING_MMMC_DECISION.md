# Aquila timing and MMMC decision

## Constraints

`constraints/asic/aquila_scl180.sdc` is an executable contract, not a timing
signoff. It fails if `AQUILA_CLOCK_PERIOD_NS` or
`AQUILA_IO_TIMING_APPROVED=1` is absent. It defines only the primary clock and
deliberately adds no unproven false paths or multicycle paths.

| Requirement | Status |
|---|---|
| Clock name/port | known: `aquila_clk` on `clk` |
| Clock period | OPEN — project approval |
| Input delay | UNKNOWN — system/interface budget required |
| Output delay | UNKNOWN — system/interface budget required |
| Input transition/output load | UNKNOWN — library/system dependent |
| Uncertainty | UNKNOWN — clock/jitter/skew budget required |
| Reset recovery/removal | must be checked from real cells; no exception invented |
| Test timing | C2S DFT mode/corner dependent |

The README/XDC state 100 MHz, while prior environment notes mention 50 MHz.
Neither is an approved requirement. The recommended interim target is 50 MHz
only because it supplies 6250 cycles/sample at 8 kHz; it is not frozen.

## MMMC

No valid MMMC setup can be produced from the inspected payload. Device HSPICE
models expose TT/SS/FF/SF/FS names, but no verified digital Liberty operating
conditions, voltage/temperature metadata, or Genus/Tempus views were found.
The final setup must define functional and test modes, setup/hold views, real
PVT and RC corners, and the approved metal stack. `SS/FF` alone is not enough
to claim signoff.

Status: **TIMING BLOCKER / PDK BLOCKER**. Synthesis must stop before
elaboration/link if required libraries, MMMC views, or approved IO timing are
missing.

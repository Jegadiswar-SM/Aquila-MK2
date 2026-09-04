# AQUILA-MK1 — C2S MMMC/RC Report

## Result

**MMMC/STA DECISION = BLOCKED.** Real FS120 SS/FF standard-cell Liberty and
max/typ/min SRAM Liberty payloads were found in C2S staging, but no integrated
lab-approved MMMC setup has executed. The PDK also contains device-model corner names and
Calibre/XRC collateral, but no verified digital Liberty operating conditions,
digital RC setup, Innovus tech LEF, or Tempus-ready MMMC views.

Observed physical option families include `ts18scl_4M1L`, `4M1T`, `4M1T3`,
`5M1L`, `5M1T`, `5M1T3`, `6M1L`, `6M1T`, and `6M1T3`. These are available
collateral families, not a selected project routing stack.

## Aquila timing baseline

| Item | Status |
|---|---|
| Clock port | `clk`, one functional clock domain by RTL inspection |
| Clock period | OPEN — project approval required; 50/100 MHz conflict remains |
| Input/output delay | UNKNOWN — system interface budget required |
| Uncertainty | UNKNOWN — clock/jitter/skew budget required |
| Setup/hold libraries | MISSING — digital Liberty absent |
| RC corners | PARTIAL physical runsets; Tempus integration unverified |
| Test views | UNKNOWN — DFT methodology unavailable |

The existing fail-fast SDC is the correct interim posture. No timing result is
claimed.

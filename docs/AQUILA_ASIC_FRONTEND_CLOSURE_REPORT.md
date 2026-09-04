# Aquila ASIC front-end closure report

Review date: 2026-09-03. This report distinguishes architecture decisions
from technology-dependent execution. No Cadence physical/signoff result is
claimed.

## Closure summary

| Area | Status | Basis |
|---|---|---|
| Functional RTL | PASS baseline / OPEN current rerun | existing baseline says 19/19; local simulator unavailable |
| Clock/reset architecture | CLOSED | RTL inspection; target period still open |
| Logical memory contract | CLOSED | direct wrapper implementation review |
| Memory adapter execution | OPEN | testbench added; `iverilog` unavailable |
| SCL180 SRAM | C2S-BLOCKED | no macro Verilog/Liberty/LEF/GDS/CDL |
| IO interface | CLOSED | exact `rls_dnn_top` port list audited |
| ASIC top/binding boundary | IMPLEMENTED | technology-neutral `aquila_scl180_top`/`aquila_scl180_io_bind` added; no PDK cells |
| SCL180 IO/ring | C2S-BLOCKED | no pad payload; SkyWater ring excluded |
| Power/ground logical domains | CLOSED | all-digital single logical domain; voltages unknown |
| DFT architecture | CLOSED recommendation | insertion, MBIST, ATPG tool/macro dependent |
| SDC | READY as fail-fast contract | period and IO approval required |
| MMMC | C2S-BLOCKED | real PVT/RC views absent |
| Genus/Conformal/Tempus/Innovus/PVS | C2S-BLOCKED | tools/collateral absent |
| DRC/LVS/IR/EM/GDS | C2S-BLOCKED | no layout, extraction, or qualified methodology |

## Required C2S inputs

Approved SCL180 libraries and rules, SRAM and IO payloads, voltage/pad plan,
DFT insertion and memory-test methodology, approved clock/interface timing
budget, MMMC corners/RC, and Cadence tool licenses. The handoff contract is in
`docs/AQUILA_GENUS_HANDOFF_CONTRACT.md`.

## Final status

**B. ASIC FRONT-END ARCHITECTURE CLOSED; PDK/CADENCE EXECUTION BLOCKED**

The technology-neutral ASIC top and IO binding boundary are now present, and
all safe pre-PDK architectural decisions are documented. Actual SCL180 SRAM,
IO, DFT, timing libraries, Cadence tools, and local HDL tools remain blocking
inputs for execution and verification. No commit was created.

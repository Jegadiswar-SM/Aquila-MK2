# Aquila tapeout readiness matrix

| Gate | Status | Evidence |
|---|---|---|
| RTL frozen | OPEN/CONFLICT | user-owned RTL edits exist in worktree; no edits made here |
| Implementation top explicit | BLOCKED/OPEN | ASIC filelist contains `aquila_scl180_top` but does not select a top; simulations select `rls_dnn_top` |
| RTL simulation | NOT YET RUN | Icarus unavailable; prior baseline claims 19/19 |
| ASIC integration simulation | NOT YET RUN | no real IO/SRAM models |
| SRAM logical contract | STATICALLY VERIFIED | wrapper source and directed TB |
| SRAM macro bound | BLOCKED | no macro payload |
| IO cells/ring bound | BLOCKED | no SCL180 digital IO views |
| Power architecture | OPEN | voltages/pad plan unknown |
| DFT/scan/MBIST | BLOCKED | insertion methodology/tool/macro support unknown |
| Synthesis/memory mapping | NOT YET RUN | Genus and digital libraries unavailable |
| Equivalence | NOT YET RUN | Conformal unavailable |
| SDC/MMMC validated | BLOCKED | period/IO budget and digital views missing |
| Floorplan/PG/placement/CTS/route | BLOCKED | Innovus/collateral unavailable |
| Extraction/Tempus | BLOCKED | real RC/library data unavailable |
| Power/IR/EM | BLOCKED | Voltus/tool and power plan unavailable |
| Antenna/DRC/LVS/ERC/density | BLOCKED | no layout; PVS unavailable |
| GLS/SDF | BLOCKED | netlist/SDF/models unavailable |
| Final GDS/manifest | BLOCKED | all upstream signoff gates open |

## Academic versus production definition

An academic demonstrator may stop at reproducible RTL plus a qualified
synthesis/netlist or a GDS exercise with explicit unbound/untested items. A
production-grade tapeout requires bound technology views, DFT/MBIST evidence,
multi-corner STA, power integrity, antenna, DRC/LVS/ERC, equivalence, GLS as
required by methodology, and final database/package consistency. Aquila is
currently suitable for the former preparatory stage only.

## Final release checklist

`PASS` is reserved for an executed, reviewable result. The current state is:

```text
[ ] RTL frozen                         OPEN/CONFLICT
[ ] RTL simulation PASS               NOT YET RUN — simulator unavailable
[ ] ASIC integration simulation PASS  NOT YET RUN — technology models absent
[x] SRAM contract reviewed             STATICALLY VERIFIED
[ ] SRAM macro bound                   BLOCKED
[ ] IO cells bound                     BLOCKED
[ ] Power architecture finalized      OPEN
[ ] DFT inserted                      BLOCKED
[ ] Scan verified                     BLOCKED
[ ] MBIST verified                    BLOCKED
[ ] Synthesis PASS                    NOT YET RUN
[ ] Memory mapping verified           NOT YET RUN
[ ] Conformal PASS                    BLOCKED
[ ] SDC validated                     BLOCKED
[ ] MMMC validated                    BLOCKED
[ ] Floorplan / power grid            BLOCKED
[ ] Placement / CTS / routing         BLOCKED
[ ] Extraction complete               BLOCKED
[ ] Tempus setup and hold PASS        BLOCKED
[ ] Transition/capacitance PASS       BLOCKED
[ ] IR / EM PASS                      BLOCKED
[ ] Antenna / DRC / LVS PASS          BLOCKED
[ ] GLS PASS                          BLOCKED
[ ] Final equivalence PASS            BLOCKED
[ ] GDS generated and verified        BLOCKED
[ ] Final manifest generated          BLOCKED
```

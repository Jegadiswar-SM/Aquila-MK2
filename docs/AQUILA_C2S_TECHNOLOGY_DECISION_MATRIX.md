# AQUILA-MK1 — C2S Technology Decision Matrix

| Decision | Evidence | Recommended option | Dependency | Confidence | Status |
|---|---|---|---|---|---|
| PDK identity | HOTCODE markers | `ts18scl_20200114_2.0` pending C2S root confirmation | actual C2S setup | MEDIUM | OPEN |
| Standard-cell library | `/home/24bvd1009/Desktop/stdcell/fs120/6M1L` has real SS/FF Liberty, LEF, GDS, CDL, Verilog | use FS120 6M1L only after C2S provenance confirmation | cross-view/tool setup | MEDIUM | CONDITIONAL |
| SRAM macro | 6M1L `SP_SRAM_spram_8192_32` and `SPRAM_8192x36` bundles | prefer 8192x32 candidate | GDS provenance, adapter, MBIST | MEDIUM | CONDITIONAL |
| SRAM banking | exact-width composition is possible | 8 × 8192x32 = 8192x256 | single-port arbitration and RMW | MEDIUM | CONDITIONAL |
| SRAM latency/collision | behavioral wrapper only | preserve one-cycle/read-first contract or normalize | macro model | LOW | BLOCKED |
| Initialization | RTL has no SRAM reset | external weight load before inference | owner + host protocol | MEDIUM | APPROVAL |
| IO/pad cells | CIO150/CIO250 6M1L physical + Liberty payload; no Verilog model | bind through `aquila_scl180_io_bind` after family/package approval | IO model, package, ESD | MEDIUM | BLOCKED |
| Power/voltage | candidate FS120/CIO/SRAM views found; integrated rail plan absent | one logical digital domain; physical rails open | PDK + package qualification | LOW | BLOCKED |
| Clock | RTL one-clock | approve 50/100 MHz requirement before SDC | system spec + timing | LOW | APPROVAL |
| Clock gating | `clk_gate_en` is status, not clock | omit ICG first chip | C2S ICG library | MEDIUM | FREEZE |
| Reset | `rst_sync` async assert/sync release | preserve RTL semantics | reset-cell methodology | MEDIUM | FREEZE |
| Scan/ATPG | no Modus/collateral | full logic scan, no compression by default | DFT methodology | LOW | BLOCKED |
| MBIST | no macro/tool support | implement only if exact SRAM supported | macro + Modus | BLOCKED | BLOCKED |
| MMMC | SS/FF standard-cell and max/typ/min SRAM Liberty found; no integrated setup | real functional/test setup/hold views | Liberty/RC/DFT | MEDIUM | BLOCKED |
| RC | XRC families present | use lab-qualified extraction flow | Quantus/Calibre method | LOW | BLOCKED |
| Physical verification | Calibre runsets present | execute lab-qualified DRC/LVS/ERC/antenna | tool + GDS/CDL | MEDIUM | BLOCKED |
| Package/pad ring | no package evidence | owner/C2S must select scope | package plan | BLOCKED | APPROVAL |

Changing the logical contract, top, memory latency, clock, IO voltage, or DFT
after synthesis is expensive; changing pad/package/macro placement after P&R
is more expensive. These decisions require explicit approval before their
respective implementation gates.

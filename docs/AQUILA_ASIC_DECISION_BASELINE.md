# Executive Decision

Current status: **B. ASIC FRONT-END ARCHITECTURE CLOSED; PDK/CADENCE EXECUTION BLOCKED**

Architecture: functional RTL and technology-neutral ASIC boundary are prepared;
no algorithm redesign is recommended. The worktree has pre-existing user edits
in `rtl/rls_dnn_top.v` and `rtl/rls_engine.v`; this review did not change them.

Memory: active 8192×256 logical SRAM path; complete-view 8192×32/36 candidates
found in C2S staging, but physical binding remains conditional on provenance,
GDS reconciliation, single-port adaptation, and MBIST support.

Clock: one clock domain; 50 MHz is a conditional interim target, not approved.

IO: exact functional port list closed; SCL180 pad/ring/package open.

Power: logical all-digital domain closed; electrical rails/pads unknown.

DFT: full logic scan plus separate SRAM MBIST assessment recommended; insertion blocked.

Timing: fail-fast SDC prepared; MMMC and IO timing budget blocked.

PDK: `HOTCODE` identity/analog payload verified; separate FS120, SRAM, and CIO
digital staging payloads found, but cross-release qualification is open.

Cadence: installations exist under `/home/install` for Xcelium, Genus,
Innovus, Tempus, Conformal, Modus, Quantus, and PVS, but they are not fully
PATH/setup/license-qualified. `/usr/sbin/pvs` resolves to Linux `lvm`, not
Cadence PVS.

MLP weights: current-topology trained image absent; model/data blocker only for
functional trained equivalence, but initialization remains a chip-use decision.

Physical design: plan prepared, no physical execution.

Signoff: no synthesis, equivalence, DFT, STA, power, IR/EM, DRC, LVS, or GDS result.

## Active-build qualification

`constraints/asic/rtl_filelist.f` contains the functional RTL, the behavioral
SRAM wrapper, and `rtl/asic/aquila_scl180_top.v`. The filelist does not itself
select a top. The Cadence simulation filelists and local regression script
select `rls_dnn_top`; no local Genus invocation proves whether the intended
implementation top is `aquila_scl180_top` or the core. The implementation
handoff must make this selection explicit.

| Claim | Result | Evidence |
|---|---|---|
| ASIC wrapper source exists | YES | `rtl/asic/aquila_scl180_top.v` |
| Wrapper is listed in ASIC filelist | YES | `constraints/asic/rtl_filelist.f` |
| Wrapper is selected as implementation top | OPEN | No executable Genus flow/top command |
| Core is used by current simulations | YES | chip filelists/testbenches |
| SCL180 pads are bound | NO | binding module is pass-through; pad views absent |

For a pad-integrated deliverable, select `aquila_scl180_top` and replace only
`aquila_scl180_io_bind` with verified SCL180 cells. For a core-only
demonstrator, select `rls_dnn_top`. `mhda_io_ring.v` remains excluded because
it instantiates SkyWater `sky130_fd_io__*` cells.

## Frozen functional hierarchy

```text
aquila_scl180_top                 [technology-neutral integration top]
├── aquila_scl180_io_bind         [pass-through boundary; C2S replaces body]
└── rls_dnn_top                   [functional core]
    ├── rst_sync
    ├── poly_decim
    ├── cbpf_2sos
    ├── aad
    ├── rcim
    ├── fwes
    ├── rls_engine
    ├── affhc
    ├── ptdl_8stage
    ├── mlp_weight_sram_wrapper   [ACTIVE weight path]
    ├── mlp_inference
    └── lat_prof
```

`mhda_io_ring` and `sky130_fd_io__gpiobuf_1to16` are obsolete for SCL180 and
must remain excluded. There are no DFT wrappers, physical SRAM cells, or
Cadence technology cells in the verified implementation path.

## MLP facts

Static RTL inspection confirms 8→128→384→128→1, 100,097 parameters, 16-bit
signed weights, 40-bit accumulation, 16-way MAC input, registered products,
QAA tanh on the first three layers, linear saturated final output, and the row
map documented in `AQUILA_MEMORY_ARCHITECTURE_DECISION.md`. Dynamic execution
was not possible here: `iverilog`, Verilator, NumPy, and pytest are unavailable.
Existing zero/stale `rtl/mlp_weights.vh` is not connected. Both discovered
PyTorch checkpoints are 8→64→32→1 and are incompatible; no current-topology
trained equivalence may be claimed.

## Master decision matrix

| ID | Decision | Current state/evidence | Options | Recommendation | Priority/status |
|---:|---|---|---|---|---|
| 1 | ASIC top | boundary now exists in `rtl/asic` | core / pad top | `aquila_scl180_top` | P1 CLOSED |
| 2 | active MLP path | RTL wiring proves wrapper active | local ROM / SRAM | SRAM wrapper | P0 CLOSED |
| 3 | logical dimensions | RTL wrapper proves 8192×256 | resize / preserve | preserve | P0 CLOSED |
| 4 | physical banking | 8192x32 candidate found | width/depth bank | 8 × 8192x32, conditional | P0 CONDITIONAL |
| 5 | macro | complete-view candidate staging bundle | compiler/macro/flops | real SRAM only; no flop substitute | P0 CONDITIONAL |
| 6 | read latency | one-cycle RTL contract | 0/1/multi | preserve one-cycle | P0 CLOSED pending macro |
| 7 | write latency | edge update | macro-specific | normalize to contract | P1 BLOCKED |
| 8 | collision | behavioral read-first | write-first/no-change | preserve read-first | P0 BLOCKED pending macro |
| 9 | initialization | no memory reset; external load | ROM/boot/load | explicit external load | P1 APPROVAL |
| 10 | weight loading | dedicated `wload_*` ports | host/test/boot | host sequence approval | P1 OPEN |
| 11 | weight source | current image absent | train/export/fake | authorized checkpoint only | P0 MODEL BLOCKER |
| 12 | clock frequency | README 100M conflicts with prior 50M | 25/50/75/100 | 50M interim | P0 APPROVAL |
| 13 | uncertainty | no approved budget | assume/approve | approve before SDC | P1 OPEN |
| 14 | gating | `clk_gate_en` not a clock | omit/ICG | omit first chip | P2 CLOSED |
| 15 | reset | async assert/sync release | alter/keep | keep RTL | P1 CLOSED |
| 16 | IO architecture | exact ports audited | core/pads | bind through IO boundary | P0 CLOSED |
| 17 | pad ring | CIO150/CIO250 physical candidates; package methodology open | core/ring | pad-integrated boundary, C2S qualification required | P0 BLOCKED |
| 18 | package | unspecified | package options | owner approval | P0 OPEN |
| 19 | power domains | one logical digital domain | one/multiple | one logical, physical TBD | P1 OPEN |
| 20 | power pads | no PDK pad set | count/rails | C2S/package | P0 BLOCKED |
| 21 | DFT | no test ports | full scan/none | full scan recommendation | P0 BLOCKED |
| 22 | scan | not inserted | full/partial | full synthesizable-flop scan | P2 OPEN |
| 23 | MBIST | macro unknown | MBIST/none | assess and implement if supported | P0 BLOCKED |
| 24 | ATPG | no tool/result | stuck/transition | both for production claim | P2 BLOCKED |
| 25 | test access | no pins | wrapper/dedicated | C2S test wrapper/pad decision | P2 OPEN |
| 26 | SDC | fail-fast clock-only | guess/approve | approve values | P1 READY-BLOCKED |
| 27 | MMMC | FS120 SS/FF and SRAM max/typ/min found; integrated setup absent | SS/FF/etc | build only from cross-qualified views | P1 BLOCKED |
| 28 | RC extraction | partial runsets only | Quantus/Calibre | C2S methodology | P3 BLOCKED |
| 29 | floorplan | no dimensions | macro-first | macro-first | P3 OPEN |
| 30 | utilization | no cell area | guess/measure | derive after Genus | P3 OPEN |
| 31 | SRAM placement | no macro geometry | central/edge | optimize from real macro | P3 OPEN |
| 32 | CTS | no cells/target | CTS/RTL clock | tool CTS | P3 BLOCKED |
| 33 | routing | stack options, no choice | 4/5/6 metal | C2S selects | P3 BLOCKED |
| 34 | IR drop | no Voltus/plan | static/dynamic | both if signoff | P4 BLOCKED |
| 35 | EM | no limits/tool | signoff/no claim | C2S signoff | P4 BLOCKED |
| 36 | antenna | Calibre runsets present | repair/diodes | C2S execute | P4 OPEN |
| 37 | filler/tap/endcap | FS120 LEF contains physical library evidence; insertion flow unverified | library-driven | use same qualified FS120 bundle | P3 BLOCKED |
| 38 | equivalence | no Conformal | RTL/netlist/DFT | staged Conformal | P2 BLOCKED |
| 39 | GLS | no netlist/SDF | pre/post DFT/route | required per methodology | P4 BLOCKED |
| 40 | PVS | executable absent; runsets Calibre | DRC/LVS/ERC | C2S execute chosen tool | P4 BLOCKED |
| 41 | GDS | none | final export | last gate only | P4 BLOCKED |
| 42 | tapeout definition | not approved | academic/production | academic demonstrator unless approved | P0 APPROVAL |

## Priority interpretation

P0 decisions block architecture/implementation entry: macro availability and
contract, clock approval, pad/package/power scope, weights/loading, and DFT
methodology. P1 decisions must be resolved before Genus: libraries, MMMC,
constraints, reset/initialization, and SRAM mapping. P2 precedes DFT insertion
and equivalence. P3 precedes Innovus. P4 precedes signoff. P5 items may remain
open only if explicitly outside the selected deliverable; none are treated as
implicitly waived here.

## Risk register

| Risk | Cause | Probability/impact | Mitigation | Owner | Blocking |
|---|---|---|---|---|---|
| flop explosion | behavioral array not mapped | high/high | Genus memory gate and real macro | C2S | yes |
| latency mismatch | macro differs from one-cycle model | medium/high | macro contract and collision TB | memory/C2S | yes |
| collision mismatch | macro mode unknown | medium/high | require read-first or normalize | memory/C2S | yes |
| macro cross-view/provenance | staging SRAM bundle not yet C2S-qualified | high/critical | reconcile GDS/LEF/CDL/Liberty/Verilog and owner approval | C2S | yes |
| IO model/package | physical CIO payload but no digital pad model/package plan | high/critical | obtain qualified IO model, padframe, ESD and package methodology | C2S | yes |
| wrong voltage | only device model classes known | medium/critical | approved power intent | C2S/owner | yes |
| wrong clock | 50/100M conflict | medium/high | approve target and budget | owner | yes |
| bad SDC/MMMC | no delays/PVT/RC | high/critical | fail-fast setup and review | STA/C2S | yes |
| scan/MBIST failure | tool/macro support unknown | medium/critical | methodology proof before DFT | DFT/C2S | yes |
| congestion | 256-bit SRAM interface/MLP | medium/high | macro-first floorplan and trial route | PD | later |
| IR/EM | no grid/pad/current data | medium/critical | Voltus/qualified analysis | PD/C2S | signoff |
| antenna/DRC/LVS | no layout or selected stack | medium/critical | run actual decks | PV/C2S | signoff |
| stale weights | old checkpoint/zero placeholder | high/high | authorized image + golden vectors | model owner | functional |
| numerical mismatch | Verilog width/QAA behavior | medium/high | exact RTL oracle + equivalence | RTL/verification | functional |
| reset mismatch | physical/DFF/DFT handling | medium/high | reset-cell and test review | RTL/DFT | yes |
| protocol mismatch | custom AXI-like semantics | medium/high | preserve named contract, interface TB | RTL | yes |
| hardcoded paths | machine-specific flow files | medium/medium | environment variables/manifests | flow owner | yes |
| LFS/payload confusion | pointer/stub artifacts | medium/high | file/type/hash manifest | project | yes |
| duplicate/obsolete RTL | SkyWater/FPGA collateral | medium/high | deterministic filelist/black-box gate | RTL/flow | yes |
| package mismatch | top ports vs pad budget | medium/high | package/pad approval | owner/C2S | yes |

## Local versus C2S

| Task | Can do locally? | Must do C2S? | Why |
|---|---|---|---|
| RTL hierarchy/path audit | yes | no | source evidence |
| logical memory/MLP contract | yes | no | current RTL |
| directed behavioral TB | yes | no | simulator permitting |
| lint/Yosys/Verilator | yes | no | local tools; currently absent |
| current weight export/equivalence | only after checkpoint | no | data blocker |
| ASIC top boundary | yes | no | technology-neutral pass-through |
| SCL180 macro selection | no | yes | no macro payload |
| IO/pad/package selection | no | yes | no digital IO views |
| Genus synthesis | no | yes | tool/libs/MMMC |
| DFT/ATPG/MBIST | no | yes | methodology/tool/macro |
| floorplan/CTS/route | no | yes | Innovus/LEF/GDS/tech |
| Tempus/Quantus/Voltus | no | yes | licensed tools and views |
| PVS/Calibre physical signoff | no | yes | layout/rules/tool |
| final GDS/package manifest | no | yes | all signoff inputs |

## Cycle-accurate memory evidence

The behavioral wrapper has two clocked processes. On a write request at edge N,
one selected 16-bit lane is updated with a nonblocking assignment. On a read
request at edge N, `rvalid` is registered and `rdata` samples the old memory
contents; the visible response is the selected row at N+1. If read and write
target the same row and same edge, the behavioral model is read-first/pre-write.
There is no reset or initialization of `mem`; reset only clears `rdata` and
`rvalid`. All 17-bit word addresses are legal in the 8192×16-word logical
capacity, including rows reserved by the current parameter image.

The directed adapter testbench exists at
`tests/asic/memory/tb_mlp_weight_sram_wrapper.v`, but execution is **UNVERIFIED
DUE TO TOOL BLOCKER** (`iverilog` missing). A physical macro with write-first,
no-change, undefined collision semantics, different latency, or incompatible
write masking cannot be accepted without an adapter/schedule change and a new
equivalence/contract run.

## Brutal consistency attack

The architecture survives the active-memory-path check, but not the silicon
entry gate. The wrapper is active, yet physical SRAM is absent; its read-first
behavior is not transferable by filename. The MLP schedule is roughly 12.2k
cycles, so README latency/throughput claims must not be reused as requirements.
The SDC exists but is intentionally not validated. The PDK has process and
physical-verification collateral and separate staging digital implementation
views, but the latter are not yet cross-qualified with the claimed root. The
SkyWater ring remains an explicit contamination risk. The PDK can therefore
support later binding only after C2S supplies a complete digital/macro/IO
bundle. GDS could technically be generated in a permissive flow and still fail
fabrication readiness; the checklist below prevents that conflation.

## Recommended final architecture

```text
functional rls_dnn_top
  -> aquila_scl180_io_bind / aquila_scl180_top
  -> logical mlp_weight_sram_wrapper contract
  -> C2S-selected width/depth SRAM composition
  -> C2S DFT wrapper: logic scan + separately assessed SRAM MBIST
  -> Genus/Conformal
  -> Innovus power/floorplan/CTS/route
  -> Quantus/Tempus/Voltus
  -> PVS/GLS/equivalence
  -> final GDS and manifest
```

Freeze the functional hierarchy, row/lane map, one-cycle logical read
contract, read-first behavioral reference, one-clock reset architecture, and
custom control protocol. Leave macro cell, banking count, voltage, pad ring,
DFT implementation, clock period, MMMC, physical geometry, and signoff values
technology/project dependent.

## Tapeout checklist status

| Gate | Status |
|---|---|
| RTL frozen | OPEN/CONFLICT — pre-existing user edits are present; no functional edits made in this review |
| RTL and ASIC integration simulation | NOT YET RUN — local Icarus/Verilator unavailable; staging SRAM models exist, digital pad models not verified |
| Logical SRAM contract and adapter | STATICALLY VERIFIED; DYNAMIC EXECUTION BLOCKED |
| Physical SRAM and IO binding | BLOCKED — candidates found; cross-view/package binding not verified |
| Power architecture | OPEN — rail and pad approvals absent |
| DFT, scan, MBIST, ATPG | ARCHITECTURE RECOMMENDED; INSERTION/VERIFY BLOCKED |
| SDC/MMMC | SDC PREPARED FAIL-FAST; MMMC BLOCKED |
| Synthesis, memory mapping, equivalence | NOT YET RUN — installations and candidate libraries found; setup/license/top qualification open |
| Floorplan, power grid, placement, CTS, route | BLOCKED — no executed physical flow or approved pad/macro assembly |
| Extraction, STA, power, IR/EM | BLOCKED — tools/installations partly present; signoff setup/license/results absent |
| Antenna, DRC, LVS, ERC, density | BLOCKED — runsets exist but no layout or executed PV result |
| GLS/SDF and final GDS | BLOCKED — all upstream implementation/signoff gates open |

## Final status

**B. ASIC FRONT-END ARCHITECTURE CLOSED; PDK/CADENCE EXECUTION BLOCKED**

This is an architecture/handoff status, not a claim of qualified synthesis,
DFT insertion, timing closure, physical implementation, or tapeout readiness.

# AQUILA ASIC IMPLEMENTATION GO/NO-GO

### GO IF

- C2S supplies real SCL180 standard-cell, SRAM, and IO views with consistent
  Verilog/Liberty/LEF/GDS/CDL and approved operating conditions.
- The project owner approves the clock target, interface timing budget,
  initialization/weight-loading sequence, package/pad scope, and DFT policy.
- Genus cleanly elaborates and maps the active memory path to intentional SRAM
  macros; Conformal, DFT/MBIST verification, Innovus, Tempus, power integrity,
  PVS, and required GLS then pass their project gates.

### NO-GO IF

- The only available memory is a filename or incompatible macro whose latency,
  collision behavior, width/depth, or physical views cannot be proven.
- Synthesis resolves the active 8192×256 memory to an unintended flop array,
  or the ASIC top resolves missing/foreign SkyWater/FPGA cells.
- Clock/interface timing, supply/pad architecture, weight initialization, or
  DFT requirements remain unapproved at the Genus/DFT entry gate.
- Any required signoff view or result is missing at tapeout release.

### CURRENT DECISION

**NO-GO for unrestricted SCL180 implementation execution; CONDITIONAL GO for
controlled C2S technology/elaboration qualification.** Real candidate payloads
and Cadence installations exist, but setup, licensing, cross-view provenance,
memory adaptation, IO/package scope, timing approval, and DFT methodology have
not been verified by execution.

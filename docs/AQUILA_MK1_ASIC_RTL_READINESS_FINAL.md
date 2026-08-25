# AQUILA-MK1 ASIC RTL READINESS REPORT

> Historical pre-interface snapshot. The current control/MLP status is
> recorded in [AQUILA_MK1_INTERFACE_AND_MLP_FINAL.md](AQUILA_MK1_INTERFACE_AND_MLP_FINAL.md).

## Executive summary

The audited repository now has a clean open-source front-end baseline and a
reproducible RTL regression: **19/19 checked-in Icarus tests pass**,
Verilator lint exits 0, and Yosys hierarchy/proc/check exits 0 with zero
structural problems.

This is **not tapeout-ready** and is not yet fully functionally verified. The
MLP cannot be compared against the intended trained behavior because the
repository contains stale zero/old-topology RTL weight data and the available
model is for 8→64→32→1, while the RTL implements 8→128→384→128→1. Strict
AXI4-Lite compliance, the FWES comment-versus-code recurrence, the register-map
high address convention, status/fault propagation, and reset-tree methodology
remain specification or laboratory decisions.

| Readiness level | Classification | Evidence |
|---|---|---|
| Level 0 — Source correctness | PASS with reviewed warnings | RTL review, Icarus, Verilator, Yosys |
| Level 1 — Functional verification | BLOCKED | Block tests pass; authoritative MLP weights/reference are missing |
| Level 2 — ASIC synthesizability | NOT VERIFIED for SCL180 | Open-source front-end passes; no Genus/SCL180 libraries here |
| Level 3 — Physical implementability | NOT VERIFIED | No synthesis, floorplan, P&R, STA, or physical collateral |
| Level 4 — Signoff readiness | BLOCKED | No DFT, timing, power, DRC, LVS, antenna, IR/EM evidence |
| Level 5 — Tapeout readiness | NOT READY | Required laboratory evidence is absent |

## Repository baseline

The checked-out repository is `/home/bolter/Aquila-MK2`; the source uses the
`rls_dnn_top`/MHDA naming. The reviewed implementation baseline was the clean
repository at commit `168b798` before controlled changes.

| Item | Finding | Status |
|---|---|---|
| Core top | `rtl/rls_dnn_top.v`, module `rls_dnn_top` | VERIFIED |
| Pad top | `rtl/mhda_io_ring.v`, module `mhda_io_ring` | VERIFIED; excluded from ASIC core |
| RTL | Verilog/SystemVerilog accepted by Icarus, Verilator, Yosys | VERIFIED |
| Core modules | 14 modules in the documented core source set | VERIFIED |
| Pad/helper modules | `mhda_io_ring` plus `sky130_fd_io__gpiobuf_1to16` | VERIFIED; excluded |
| Clock domains | One logical `clk` domain found | INFERRED; CDC tool not run |
| Reset | Raw async input, synchronized release, qualified synchronous datapath reset | VERIFIED from RTL |
| Input/output | 32-bit input stream; 16-bit output stream | VERIFIED |
| Control | Custom AXI-like valid/ready register interface | VERIFIED; strict AXI4-Lite NOT VERIFIED |
| Memory | Behavioral 8192×256-bit weight store, one-cycle read response | VERIFIED |
| SCL180 collateral | Not present locally | NOT ESTABLISHED — REQUIRED FROM LAB |

The `.npz` files are Git-LFS pointer text rather than usable NPZ data.
`models/best_mlp.pt` is a valid archive but describes the older topology. The
header in `rtl/mlp_weights.vh` identifies stale zero/old-topology weights; it is
not included in the current core source list.

## Verified hierarchy

```text
rls_dnn_top
├── rst_sync                 (u_rst_sync)
├── poly_decim               (u_poly)
├── cbpf_2sos                (u_cbpf)
├── aad                      (u_aad)
├── rcim                     (u_rcim)
├── fwes                     (u_fwes)
├── rls_engine               (u_rls)
├── affhc                    (u_affhc)
├── ptdl_8stage              (u_ptdl)
├── mlp_weight_sram_wrapper  (u_sram)
├── mlp_inference             (u_mlp)
├── plwd                     (u_plwd)
└── lat_prof                 (u_latprof)
```

All 14 core modules resolve under Yosys `hierarchy -check`. No unresolved
reference, duplicate core definition, or second core top was found in the
reviewed source set. The pad wrapper is deliberately outside this hierarchy.

## Module-by-module review

| Module | Actual role | Result |
|---|---|---|
| `rst_sync` | Two-flop reset release synchronizer | PASS; final reset methodology lab-dependent |
| `poly_decim` | 1:1/1:2/1:4 valid phase generation | PASS in directed pulse test |
| `cbpf_2sos` | Two-section fixed-point bandpass pipeline | PASS in reset/sign/valid test |
| `aad` | Squared-energy/activity detector | PASS in pipeline-valid/reset test |
| `rcim` | Correlation/normalization and retained NR path | PASS in positive/negative/NR tests |
| `fwes` | Executable recurrence as coded | PASS for code recurrence; comment/spec unresolved |
| `rls_engine` | Eight-tap RLS update engine | PASS for saturation/NR-directed checks; full reference incomplete |
| `affhc` | Hysteresis/adaptive lambda controller | PASS for nominal/extreme-width cases |
| `ptdl_8stage` | Eight-stage residual history/feature packing | PASS in sequence/reset test |
| `mlp_weight_sram_wrapper` | Behavioral memory abstraction | PASS as RTL model; macro mapping blocked |
| `mlp_inference` | 8→128→384→128→1 time-multiplexed MLP | Schedule PASS; trained equivalence blocked |
| `plwd` | Watchdog/recovery/fault registers | PASS in standalone/long-transaction tests |
| `lat_prof` | Latency counters/readout | Front-end PASS; status contract needs review |
| `rls_dnn_top` | Integration, streaming, control, reset, output | Directed integration PASS; trained result blocked |

## Integration and interface audit

The top now accepts an input only on a real `s_axis_tvalid && s_axis_tready`
transfer and serializes the existing one-transaction MLP datapath. Output data
is held stable while `m_axis_tvalid && !m_axis_tready`. Directed tests cover
admission, PTDL/MLP alignment, output backpressure, child read response, and a
complete long transaction through the behavioral MLP schedule.

The MLP schedule measured 12,186 cycles and 6,921 weight read commands with
the zero behavioral memory. The watchdog is qualified by an active transaction
and configured to 16,384 cycles. This passed the long-transaction test, but is
not a timing or throughput signoff value.

The control interface is not proven AXI4-Lite. Current RTL requires address
and write data valid together in several child blocks, does not expose
`WSTRB`, and uses pulse-style ready behavior. It must remain documented as a
custom AXI-like interface unless the project specification authorizes a
protocol change.

Actual top-level module-window decode is `address[6:4]`:

| Window | Block |
|---:|---|
| `0x00–0x0F` | AFFHC |
| `0x10–0x1F` | AAD |
| `0x20–0x2F` | CBPF |
| `0x30–0x3F` | PLWD |
| `0x40–0x4F` | RCIM |
| `0x50–0x5F` | RLS control |
| `0x60–0x6F` | LATPROF read path |

RLS control comments refer to `0xA0/0xA4/0xA8`, but bit 7 is ignored by the
actual decode. This is **REQUIRES SPECIFICATION** and was not silently
remapped. Fault/status signals such as RCIM reference-channel fault and AAD
activity are present internally but not fully propagated to top-level status;
their required behavior is also **REQUIRES SPECIFICATION**.

## Clock, reset, CDC, and memory

No data-derived, divided, muxed, or combinationally gated clock was found in
the core hierarchy. Enables remain enables. A formal CDC run is **NOT
VERIFIED**; source review found no second clock domain.

Reset assertion enters through raw `rst_n`; release is synchronized by
`rst_sync`. Watchdog recovery is now a synchronous soft reset for the major
datapath blocks. Verilator still reports `SYNCASYNCNET` because the
synchronized reset is used in both reset-sensitive and synchronous conditions.
This warning remains visible for laboratory reset-tree review.

The MLP memory is logically 8192 rows × 256 bits = 2,097,152 bits. Its
interface is `clk`, `rst_n`, `ren`, `raddr[12:0]`, `rdata[255:0]`, `rvalid`,
and sequential 16-bit lane programming through `wload_en`,
`wload_addr[16:0]`, `wload_data[15:0]`. It is a behavioral model, not an ASIC
macro. Macro timing, read-during-write behavior, test interface, and
availability are **LAB PDK DEPENDENCY — FILL FROM ACTUAL SCL180 INSTALLATION**.

## Arithmetic and MLP verification

Signed extensions, accumulator sizing, y-hat saturation, CBPF/AAD valid
pipelines, AFFHC delta width, and RCIM sign handling were reviewed and have
directed evidence. The existing Newton-Raphson implementation was retained;
its isolated sweep passes.

The MLP schedule and terminal SRAM-row accesses are verified. Mathematical MLP
equivalence is **BLOCKED — AUTHORITATIVE WEIGHTS REQUIRED**. No stale, zero, or
randomly generated weight data may be treated as the intended trained model.

## Bug inventory

| Finding | Classification | Disposition |
|---|---|---|
| FWES illegal declaration | CONFIRMED | Fixed; compile regression PASS |
| PLWD multiple procedural drivers | CONFIRMED | Fixed; standalone test PASS |
| MLP admission while busy | CONFIRMED | Fixed with one-in-flight admission |
| RLS/MLP valid/residual alignment | CONFIRMED | Fixed; directed alignment PASS |
| `step_cnt << 4` truncation | REFUTED as stated | Explicit sizing retained for clarity |
| MLP terminal SRAM row | CONFIRMED | Fixed; terminal rows observed |
| Watchdog reset during normal MLP | PARTIALLY CONFIRMED | Active qualification and long-path PASS |
| CBPF uninitialized pipeline | CONFIRMED | Fixed |
| AAD stale/misaligned square pipeline | PARTIALLY CONFIRMED | Fixed and tested |
| Polydecim pulse behavior | CONFIRMED | Fixed; exact pulse test PASS |
| Negative RLS y-hat saturation | CONFIRMED | Fixed; boundary test PASS |
| RCIM signedness/sign-bit issue | CONFIRMED | Fixed; NR retained/tested |
| AFFHC counter/delta widths | CONFIRMED | Fixed and boundary tested |
| AXI-like write protocol | CONFIRMED non-compliant AXI4-Lite | Custom contract required |
| Stale top read data | CONFIRMED | Fixed; back-to-back read PASS |
| Output overwrite under stall | CONFIRMED | Fixed; stability test PASS |
| Missing fault/status propagation | CONFIRMED | Specification decision needed |
| PLWD-derived async reset risk | CONFIRMED risk | Synchronous soft reset added; signoff pending |
| Implicit nets/declaration ordering | CONFIRMED | Cleaned; front-end PASS |
| FPGA memory assumptions | CONFIRMED risk | Technology-neutral wrapper documented |
| SkyWater pad wrapper | CONFIRMED | Excluded; SCL180 wrapper required |
| FPGA constraints | CONFIRMED | ASIC template added |
| Regression failure masking | CONFIRMED | Fail-fast script added |
| Missing/stale MLP weights | CONFIRMED | HARD BLOCKER; no fabrication |
| FWES comment/code discrepancy | REQUIRES SPECIFICATION | Executable recurrence preserved |

## Verification evidence

| Check | Result |
|---|---|
| Icarus directed/integration regression | PASS — 17/17 |
| Verilator lint | PASS exit code; reviewed warnings remain |
| Yosys read/elaborate/hierarchy/proc/check | PASS exit code; 0 structural problems |
| Separate assertion-engine run | NOT VERIFIED |
| Formal equivalence | NOT VERIFIED |
| RTL vs trained software model | BLOCKED by missing current-topology weights |
| Gate-level simulation | NOT VERIFIED |
| CDC analysis | NOT VERIFIED |
| Synthesis with SCL180 libraries | NOT VERIFIED |
| Timing/power/physical signoff | NOT VERIFIED |

The regression is reproducible with `make -C sim` or
`./scripts/run_iverilog_regression.sh`; it rebuilds its own binaries, uses
timeouts, checks PASS markers, and propagates failures.

## ASIC portability and laboratory package

The core synthesis source list and exclusions are recorded in
`docs/SCL180_LAB_INTEGRATION.md`. Exclude `rtl/mhda_io_ring.v`,
`rtl/mlp_weights.vh`, FPGA XDC/legacy constraints, testbenches, model/data
files, and simulation artifacts from the core Genus source set.

The pad wrapper requires replacement with actual SCL180 IO cells. Required
SCL180 standard-cell, IO, memory, Liberty, LEF, GDS, extraction, timing-corner,
DFT, DRC, LVS, antenna, and reliability collateral is not present here:

**LAB PDK DEPENDENCY — FILL FROM ACTUAL SCL180 INSTALLATION.**

The ASIC SDC file is a template only. Target clock period, uncertainty,
interface delays, drive, loads, operating corners, and exceptions are not
established by this repository. No Cadence commands are claimed because the
installed release and site methodology were not available here.

## Required next steps

1. Obtain authoritative current-topology weights, conversion checksum, and
   golden vectors; rerun MLP/reference and full-pipeline checks.
2. Resolve the control-interface contract: custom AXI-like versus strict
   AXI4-Lite, including independent AW/W handling and `WSTRB`.
3. Resolve the RLS control address convention and required fault/status
   propagation from the project specification.
4. Have the lab select and characterize the actual SCL180 memory solution and
   connect it to the documented logical wrapper interface.
5. Replace the SkyWater pad wrapper with the actual SCL180 pad integration.
6. Fill the ASIC SDC template from approved clock/interface requirements.
7. Run Genus elaboration/synthesis, review warnings, then perform
   post-synthesis equivalence or gate simulation before Innovus.
8. Execute DFT, MMMC STA, power, CTS, routing, extraction, DRC, LVS, antenna,
   IR/EM, and foundry-specific tapeout checks in the laboratory.

## Project status board

| Stage | Status | Blocking issue | Evidence | Next gate |
|---|---|---|---|---|
| Repository baseline | PASSED | None | Inventory/source review | RTL hierarchy |
| RTL hierarchy | PASSED | None | Yosys hierarchy check | Integration |
| Integration | PASSED | Spec-dependent status/control items | Directed top tests | Functional golden vectors |
| Functional verification | BLOCKED | Authoritative MLP weights | 17/17 block/integration tests | Current weights/reference |
| Clock/reset | IN PROGRESS | Reset-tree methodology | Single-clock review; lint warning | Lab reset review |
| Memory | BLOCKED | SCL180 macro unavailable | Behavioral wrapper only | Macro selection/interface |
| Arithmetic | PASSED | Full reference breadth limited | Directed fixed-point tests/NR sweep | Golden expansion |
| AXI | BLOCKED | Strict protocol contract unspecified | Stream tests pass; control custom | Interface decision |
| ASIC compatibility | IN PROGRESS | PDK wrapper/memory | Front-end tools pass | Lab source binding |
| SCL180 setup | BLOCKED | PDK not local | Handoff template | Lab collateral |
| Genus | NOT STARTED | No Cadence/SCL180 here | No run | Library/MMMC setup |
| Post-synthesis verification | NOT STARTED | No netlist | No run | Genus netlist |
| Innovus | NOT STARTED | No physical setup | No run | Netlist/MMMC |
| CTS | NOT STARTED | No physical run | No run | Placement |
| Routing | NOT STARTED | No physical run | No run | CTS |
| STA | NOT STARTED | No timing libraries/constraints | Template only | MMMC/SDC |
| Power | NOT STARTED | No activity/cells | No run | Synthesis/STA |
| DRC | NOT STARTED | No PDK/deck/layout | No run | Routed layout |
| LVS | NOT STARTED | No PDK/deck/layout | No run | Routed layout |
| GDSII | NOT STARTED | No physical implementation | No run | Signoff |
| Tapeout readiness | BLOCKED | Functional and lab gates remain | This report | Complete all gates |

## Final decision

The repository is suitable to transfer to the laboratory as a **clean
front-end integration baseline**, subject to the explicit blockers above. It
must not be labeled ASIC-ready for SCL180, signoff-ready, or tapeout-ready
until the missing trained weights/specifications and actual Cadence/SCL180
implementation evidence are supplied.

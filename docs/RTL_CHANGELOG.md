# Aquila-MK1 RTL change log

The checked-out repository is named `Aquila-MK2`; this log uses the requested
project designation while identifying the actual source. No Type-D algorithmic
change was made.

| ID | File / module | Correction | Type | Verification | Result |
|---|---|---|---|---|---|
| C01 | `rtl/fwes.v` / `fwes` | Moved the illegal block-local intermediate declaration to module scope; recurrence unchanged. | A | `tb_fwes`, Icarus, Yosys | PASS |
| C02 | `rtl/plwd.v` / `plwd` | Consolidated fault-register ownership, made clear priority explicit, added default state and active-transaction timeout qualification. | B/C | `tb_plwd`, `tb_top_long_transaction` | PASS |
| C03 | `rtl/rls_dnn_top.v` / admission | Added one-in-flight admission state so the existing MLP cannot accept a second unbuffered sample. | C | `tb_top_admission`, regression | PASS |
| C04 | `rtl/rls_dnn_top.v` / output | Held output data while `m_axis_tvalid && !m_axis_tready`. | C | `tb_top_output_hold` | PASS |
| C05 | `rtl/rls_dnn_top.v` / RLS-PTDL-MLP path | Delayed PTDL valid and held the matching RLS error through MLP completion. | C | `tb_top_alignment` | PASS |
| C06 | `rtl/rls_dnn_top.v` / read response | Added read-accept/pending tracking and aligned child response data with top-level RVALID. | C | `tb_top_read` | PASS |
| C07 | `rtl/rls_dnn_top.v` / decimation | Advanced decimation only on an accepted transfer and captured the pre-update phase decision so the first sample is not dropped. | B/C | `tb_poly_decim`, `tb_top_long_transaction` | PASS |
| C08 | `rtl/rls_dnn_top.v` and datapath blocks / reset | Added synchronous `srst` datapath reset for watchdog recovery while retaining raw async assertion at reset boundaries. | B | block tests, Verilator | PASS; reset-tree review remains required |
| C09 | `rtl/cbpf_2sos.v` | Reset multiplier/valid pipeline and make sign extension/truncation explicit. | B | `tb_cbpf_2sos` | PASS |
| C10 | `rtl/aad.v` | Reset and align square multiplication valid/data pipeline. | B | `tb_aad` | PASS |
| C11 | `rtl/poly_decim.v` | Implement exact 1:1, 1:2, and 1:4 pulse patterns and soft reset. | B | `tb_poly_decim` | PASS |
| C12 | `rtl/rcim.v` | Make product extension and correlation sign handling explicit; retain Newton-Raphson. | B | `tb_rcim`, `tb_rcim_negative`, NR sweep | PASS |
| C13 | `rtl/rls_engine.v` | Correct signed y-hat accumulator saturation limits. | B | `tb_rls_engine_sat`, NR sweep | PASS |
| C14 | `rtl/affhc.v` | Clear stale hysteresis counters and widen signed delta operands. | B | `tb_affhc` | PASS |
| C15 | `rtl/ptdl_8stage.v` | Add synchronous history/valid reset. | B | `tb_ptdl_8stage` | PASS |
| C16 | `rtl/mlp_inference.v` | Add explicit index/address sizing and reset internal arrays/pipelines; topology and schedule unchanged. | B | `tb_mlp_schedule`, Yosys, Verilator | PASS; trained equivalence blocked |
| C17 | `rtl/mlp_inference.v` | Preserve terminal weight read commands; terminal rows 79, 6239, and 6255 are observed. | B | `tb_mlp_schedule` | PASS |
| C18 | `rtl/mlp_weight_sram_wrapper.v` | Document technology-independent 8192×256, one-cycle-read logical memory boundary. | A/B | Icarus, Yosys | PASS; real macro unavailable |
| C19 | `rtl/lat_prof.v` | Give the free-counter snapshot one procedural owner. | A | Verilator, Yosys | PASS |
| C20 | `sim/Makefile`, `scripts/run_iverilog_regression.sh` | Add fail-fast compile/sim/timeout/PASS-marker checking and exclude the SkyWater pad wrapper. | A | `make -C sim` | PASS, 17/17 |
| C21 | `constraints/asic/rls_dnn_top.sdc.template` | Add an ASIC-only TODO template; no clock, cell, or library values invented. | A | file review | PASS as template; not executable |
| C22 | `docs/SCL180_LAB_INTEGRATION.md` | Document lab source boundary, exclusions, logical memory interface, IO requirements, and PDK dependencies. | A | file review | PASS |
| C23 | `rtl/rls_dnn_top.v` / control decode | Replaced conflicting `[6:4]` module selection with the canonical `[7:5]` byte-window convention, restoring documented 0x10/0xA0 reachability. | B | `tb_control_plane`, full regression | PASS |
| C24 | `rtl/rls_dnn_top.v` / custom write acceptance | Made coupled AWVALID/WVALID acceptance single-shot while idle and held B response behavior deterministic; no WSTRB or independent-channel architecture was added. | B/C | `tb_control_plane`, full regression | PASS |
| C25 | `tb/tb_control_plane.v`, `tb/tb_fault_status_top.v` | Added executable canonical-map, coupled-write, invalid-address, fault-read, fault-clear, and IRQ/recovery tests. | A | full regression | PASS; 19/19 |
| C26 | `scripts/export_mlp_memory.py`, `tests/mlp_golden/` | Added strict current-topology checkpoint validation, deterministic Q1.15 SRAM-image mapping, manifest/checksum generation, and exact integer reference harness. | A | Python syntax check; execution awaits authorized model | NOT VERIFIED until model is supplied |
| C27 | `tests/mlp_golden/reference_model.py`, `tb/tb_mlp_transaction.v`, `tests/mlp_golden/run_structural.sh`, `tests/mlp_golden/test_reference_contract.py` | Corrected the reference model to the executable W1/B1 row map and added a direct non-authoritative MLP transaction/zero-memory structural check. | A | Reference self-check; direct Icarus MLP test | PASS; trained equivalence remains blocked |
| C28 | `tests/mlp_golden/reference_model.py`, `tb/tb_mlp_qaa_oracle.v`, `tests/mlp_golden/run_structural.sh` | Matched the reference to the compiled RTL's 16-bit QAA expression widths and added an Icarus oracle; no RTL arithmetic was changed. | A | Reference self-check; QAA oracle | PASS; numerical intent requires specification review |

## Explicitly not changed

- RLS, FWES executable recurrence, RCIM Newton-Raphson, MLP topology,
  activation, and fixed-point algorithm were not redesigned.
- The custom control interface was not silently converted to AXI4-Lite.
- No SCL180 cell, macro, timing model, IO model, Cadence command, or foundry
  collateral was created.
- No weights were invented, randomized, or regenerated.

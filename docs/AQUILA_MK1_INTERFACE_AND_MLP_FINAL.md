# AQUILA-MK1 INTERFACE AND MLP FINAL REPORT

## 1. Executive Summary

The four remaining front-end issues have been resolved to the strongest state
supported by repository evidence without fabricating weights or converting the
interface into an unrequested protocol.

- The MLP weight issue remains **BLOCKED** by missing authoritative current-
  topology weights; strict import and exact reference infrastructure is now
  available.
- The control path is now a **VERIFIED CUSTOM CONTROL INTERFACE**, explicitly
  not AXI4-Lite. Coupled write acceptance is deterministic.
- The register map is canonicalized to byte-addressed 32-byte windows at
  0x00/0x20/0x40/0x60/0x80/0xA0/0xC0 and is verified by directed tests.
- PLWD fault/status visibility and clear semantics are specified and verified;
  internal RCIM/CBPF/AAD status remains explicitly internal rather than being
  silently promoted to a new interrupt behavior.

## 2. Baseline

| Item | Result | Evidence |
|---|---|---|
| Baseline commit | VERIFIED | `168b7989e9a71bbcfa614903f55880ce68892b3d` |
| Existing repaired regression | PASS — 17/17 | `make -C sim` before interface changes |
| Current regression | PASS — 19/19 | `make -C sim` after interface/control tests |
| Verilator lint | PASS exit code | Reviewed warnings remain |
| Yosys hierarchy/proc/check | PASS exit code | 0 structural problems |
| Python infrastructure syntax | PASS | `py_compile` for exporter/reference harness |
| SCL180/Cadence | NOT VERIFIED | Not available on workstation |

The frozen pre-change state is recorded in
`docs/AQUILA_MK1_PRE_INTERFACE_BASELINE.md`.

## 3. MLP Weight Provenance

The RTL requires topology 8→128→384→128→1 and 100,097 parameters. The
available checkpoint archives contain six tensors corresponding to 8→64→32→1
and 2,689 parameters. The root and `scripts/models` checkpoints are also not
byte-identical. `rtl/mlp_weights.vh` contains 100,097 zero words and labels
itself a stale placeholder.

Result: **MLP WEIGHTS — BLOCKED — AUTHORITATIVE MODEL/WEIGHTS REQUIRED.**

Detailed evidence, SHA-256 values, and the import contract are in
[`MLP_WEIGHT_PROVENANCE.md`](MLP_WEIGHT_PROVENANCE.md). No model was retrained,
converted, or loaded into the RTL.

The strict importer is
[`scripts/export_mlp_memory.py`](../scripts/export_mlp_memory.py). It rejects
missing/extra keys, shape mismatches, non-finite values, and topology mismatch,
then records source/image checksums and the exact 8192×16-bit-lane memory map.

## 4. MLP Numerical Contract

The exact reference contract follows executable RTL behavior:

- signed 16-bit Q1.15 features, weights, and biases;
- signed 32-bit products sign-extended into a 40-bit accumulator;
- four-segment QAA activation for the first three layers;
- the RTL's executable bias alignment and output slice;
- signed final saturation to `0x7FFF`/`0x8000`;
- one-cycle memory read response and the exact row/lane map.

The bias alignment is intentionally documented as implemented, not silently
corrected. Whether the future trained model's bias export uses the same
alignment is **REQUIRES SPECIFICATION** until authoritative provenance exists.

The exact integer reference is in
[`tests/mlp_golden/reference_model.py`](../tests/mlp_golden/reference_model.py).

## 5. Golden-Vector Verification

The harness and vector specification are present in
[`MLP_GOLDEN_VECTOR_SPEC.md`](MLP_GOLDEN_VECTOR_SPEC.md) and
[`tests/mlp_golden/`](../tests/mlp_golden/). The harness was executed against
missing inputs and correctly returned:

```text
MLP GOLDEN VERIFICATION BLOCKED: authoritative image/vectors absent
```

Therefore:

| Check | Status |
|---|---|
| MLP schedule/terminal-row behavior | VERIFIED |
| MLP reference implementation infrastructure | VERIFIED as syntax/importable infrastructure |
| MLP golden vectors | BLOCKED |
| RTL-vs-reference bit-exact equivalence | BLOCKED |
| Full trained end-to-end pipeline | BLOCKED |

## 6. Control Interface Decision

The implementation does not meet strict AXI4-Lite requirements: it has no
`WSTRB`, child writes require AWVALID and WVALID together, and the original
ready/response timing could acknowledge inconsistently. Existing repository
usage does not establish a strict AXI4-Lite host contract.

Decision: preserve the ports and define the interface as the **Aquila Custom
Control Interface**. A coupled request requires both valid signals while idle;
one response may be outstanding; invalid writes return `SLVERR`; reads are
single-outstanding and held until `RREADY`.

The decision matrix and rationale are in
[`INTERFACE_DECISION_RECORD.md`](INTERFACE_DECISION_RECORD.md). The executable
contract is in [`AQUILA_CONTROL_INTERFACE_SPEC.md`](AQUILA_CONTROL_INTERFACE_SPEC.md).

## 7. AXI4-Lite Compliance Result

| Area | Result |
|---|---|
| Strict AXI4-Lite | NOT VERIFIED / NOT SELECTED |
| Aquila Custom Control Interface | VERIFIED |
| Independent AW/W arrival | Intentionally unsupported and documented |
| WSTRB | Not present; intentionally not added |
| Read response stability | VERIFIED by existing and new tests |
| Invalid access behavior | VERIFIED by new control-plane test |

The interface must not be called AXI4-Lite in future lab integration material.
An external AXI4-Lite host requires a separately specified adapter.

## 8. Register Map

The former `[6:4]` top-level decode made `0xA0` select CBPF and made AFFHC
offset `0x10` inaccessible. The canonical correction uses `[7:5]`, consistent
with child address widths and active RLS/AFFHC address comments. LATPROF is a
read-only C0–EB extension because it exposes eleven 32-bit words.

| Window | Block |
|---:|---|
| 0x00–0x1F | AFFHC |
| 0x20–0x3F | AAD |
| 0x40–0x5F | CBPF |
| 0x60–0x7F | PLWD |
| 0x80–0x9F | RCIM |
| 0xA0–0xBF | RLS control |
| 0xC0–0xEB | LATPROF read-only |

The complete offset/reset/access table is in
[`AQUILA_REGISTER_MAP.md`](AQUILA_REGISTER_MAP.md). New tests verify AFFHC
0x10, AAD 0x20, RLS 0xA0, read-only/invalid writes, and deterministic reads.

## 9. Fault/Status Architecture

The existing external behavior is preserved:

- `irq_fault` is the PLWD watchdog fault notification pulse;
- PLWD fault type 01 means no-valid timeout, 10 means repeated output;
- PLWD fault count and sample-count log are readable;
- fault clear at 0x6C clears IRQ/type/count, while sample count remains until
  reset;
- `pipeline_srst` is an internal recovery reset;
- RCIM reference fault, CBPF clipping, AAD activity, and AFFHC debug state are
  internal-only and are not silently aggregated into `irq_fault`.

This distinction is specified in
[`AQUILA_FAULT_STATUS_SPEC.md`](AQUILA_FAULT_STATUS_SPEC.md) and exercised by
`tb_fault_status_top`. The top-level fault/status contract is therefore
**SPECIFIED + VERIFIED for current external visibility**.

## 10. RTL Changes

| Change | Classification | Reason | Evidence |
|---|---|---|---|
| Top decode `[6:4]` → `[7:5]` | B | Restore one canonical reachable map | `tb_control_plane` |
| Coupled write acceptance/response | B/C | Prevent acceptance/response ambiguity without adding WSTRB or a FIFO | `tb_control_plane` |
| Existing top read test addresses | A/B | Align tests with canonical map | `tb_top_read` |
| Control/fault tests | A | Verify new contract and no hidden side effects | 19/19 regression |
| Weight exporter/reference infrastructure | A | Deterministic future import/equivalence | Python syntax; blocked execution |

No algorithmic, MLP-topology, RLS, filter, or fixed-point datapath redesign was
made in this phase.

## 11. Verification Results

| Check | Result |
|---|---|
| Existing block/integration tests | PASS — 17/17 |
| New control-plane test | PASS |
| New top fault/status test | PASS |
| Current complete regression | PASS — 19/19 |
| Verilator lint | PASS exit code; reviewed warnings remain |
| Yosys hierarchy/proc/check | PASS; 0 structural problems |
| Golden harness missing-input behavior | PASS — correctly reports BLOCKED |
| Actual golden-vector comparison | BLOCKED |
| Formal protocol assertion engine | NOT VERIFIED |

## 12. ASIC Impact

The changes remain technology-independent RTL. No FPGA primitive, clock,
memory macro, SCL180 cell, or Cadence command was introduced. The control
correction adds only small decode/acceptance logic; the map correction does not
alter datapath timing or architecture. The weight exporter produces a logical
loader image for the existing wrapper and does not fabricate an SRAM macro.

The remaining Verilator warnings are reviewed front-end warnings, including
unused internal status/debug outputs, behavioral memory representation, MLP
reset-array assignment style, and the known synchronized-reset async-use
warning. They are not SCL180 synthesis or timing results.

## 13. Remaining Blockers

1. Authoritative current-topology MLP checkpoint and provenance.
2. MLP golden vectors and bit-exact RTL/reference equivalence.
3. Confirmation of future host integration; if strict AXI4-Lite is required,
   implement and verify a separate adapter or approve a larger interface
   change.
4. SCL180 memory macro selection, IO wrapper, libraries, Cadence setup, DFT,
   synthesis, STA, power, P&R, DRC, LVS, antenna, and reliability evidence.

## 14. SCL180 Integration Requirements

The laboratory must use the existing core top `rls_dnn_top`, replace the
SkyWater pad wrapper, select an actual SCL180 memory implementation for the
documented logical interface, and fill the ASIC SDC template. The control
interface presented to the wrapper is the Aquila Custom Control Interface;
the lab must not assume AXI4-Lite without an approved adapter.

See [`SCL180_LAB_INTEGRATION.md`](SCL180_LAB_INTEGRATION.md). All foundry
collateral remains:

**LAB PDK DEPENDENCY — FILL FROM ACTUAL SCL180 INSTALLATION.**

## 15. Final Readiness Classification

| Area | Status | Evidence |
|---|---|---|
| MLP weights | BLOCKED | No authoritative current-topology artifact |
| MLP golden vectors | BLOCKED | Harness exists; source image absent |
| MLP RTL equivalence | BLOCKED | Cannot compare trained behavior |
| Control interface | VERIFIED CUSTOM CONTROL INTERFACE | Spec, decision record, directed test |
| AXI4-Lite | NOT VERIFIED / NOT SELECTED | Missing WSTRB and independent AW/W by design |
| Register map | SPECIFIED + VERIFIED | Canonical `[7:5]` map and control-plane test |
| Fault/status | SPECIFIED + VERIFIED for external PLWD contract | Fault/status spec and top test |
| Regression | PASS | 19/19 |
| ASIC RTL | VERIFIED front-end baseline | Verilator/Yosys pass; SCL180 not run |
| SCL180 integration | NOT VERIFIED | PDK/Cadence collateral unavailable locally |

Final decision: the repository is a clean, deterministic ASIC front-end
handoff baseline with a verified custom control/register/fault contract. It
cannot be declared fully functionally verified or tapeout-ready until
authoritative MLP weights and the laboratory implementation evidence exist.

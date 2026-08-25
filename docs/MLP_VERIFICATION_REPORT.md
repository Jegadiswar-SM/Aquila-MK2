# Aquila-MK1 MLP Verification Report

Investigation date: 2026-08-25 UTC

## Status summary

| Verification | Status | Evidence |
|---|---|---|
| MLP structure | **VERIFIED** | RTL extraction, Yosys hierarchy/proc/check, topology and parameter count |
| MLP numerical contract | **VERIFIED as executable RTL behavior; specification risk recorded** | Contract, integer reference, compiled QAA oracle |
| MLP transaction behavior | **VERIFIED for tested contract** | Direct MLP test: busy-time input, repeated transactions, soft reset, zero-memory completion |
| MLP schedule/terminal addressing | **VERIFIED** | Existing schedule test; direct test; terminal rows 79, 6239, 6255 observed |
| MLP RTL-weight golden vectors | **NOT ESTABLISHED** | No functional deterministic weight image exists; zero placeholder is not connected to active SRAM |
| Trained-model equivalence | **BLOCKED** | Current-topology authoritative model/weights absent; committed checkpoints are 8→64→32→1 |
| End-to-end trained pipeline | **BLOCKED** | Same missing model/weight artifact; dataset payloads are unavailable LFS pointers |

## Executed checks

```text
19/19 existing Aquila regression: PASS
Direct MLP structural/transaction/zero-memory check: PASS
Reference contract self-check: PASS
Compiled QAA expression-width oracle: PASS
Verilator lint: PASS
Yosys hierarchy/proc/check: PASS, 0 structural problems
```

The direct MLP check reports a measured zero-memory inference latency of 12,180
cycles from its testbench acceptance marker. The separate schedule test remains
the authority for terminal-row coverage and reports the previously established
12,186-cycle schedule measurement. The small measurement difference is due to
testbench observation point, not a claimed change to the MLP schedule.

## Important distinction

The direct test uses a zero-valued behavioral memory response solely to exercise
the existing FSM, SRAM-valid pipeline, busy-time admission behavior, repeated
transactions, and reset cancellation. It is not a trained network and is not
reported as a golden-vector or model-equivalence pass.

The Python reference model now uses the executable RTL row map. In particular,
W1 begins at row 0 and B1 at row 64. The previous infrastructure tuple used
incorrect first-layer bases (72/64); that test-infrastructure defect was
corrected without changing RTL. The model also reproduces the compiled 16-bit
QAA expression widths. This exposes a specification risk: the RTL's first
segment gives `qaa_tanh(8192)=0` and `qaa_tanh(2)=-1`, rather than the expected
full-width linear approximation. No RTL correction was made because that would
be a functional change requiring an approved numerical contract.

## Final conclusion

The repository supports a verified structural and transaction-level MLP
statement. It does not support a trained-model or bit-exact weight-image
statement. The blocker is therefore retained and is documented precisely in
`MLP_VERIFICATION_BLOCKER.md`.

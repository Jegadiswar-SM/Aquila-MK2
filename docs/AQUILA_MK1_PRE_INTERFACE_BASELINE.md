# Aquila-MK1 pre-interface baseline

This document freezes the starting point for the weight, control-interface,
register-map, and fault/status work. It is not a new RTL revision.

## Repository state

| Item | Value | Status |
|---|---|---|
| Working directory | `/home/bolter/Aquila-MK2` | VERIFIED |
| Baseline commit | `168b7989e9a71bbcfa614903f55880ce68892b3d` (`codes`) | VERIFIED |
| Working tree | Contains the previously audited uncommitted RTL, tests, scripts, docs, and SDC template | VERIFIED |
| PDK/Cadence | Not present on this workstation | NOT ESTABLISHED — LAB DEPENDENCY |

## Existing verification baseline

| Check | Result | Evidence |
|---|---|---|
| Icarus regression | PASS — 17/17 | `make -C sim` |
| Direct executable regression | PASS — 17/17 | `scripts/run_iverilog_regression.sh` |
| Verilator lint | PASS exit code | `make -C sim lint`; reviewed warnings remain |
| Yosys hierarchy/proc/check | PASS exit code | top `rls_dnn_top`; 0 structural problems |
| Diff whitespace check | PASS | `git diff --check` |

The regression output includes reviewed Icarus array-sensitivity warnings from
the behavioral MLP arrays. Verilator warnings include unused/debug signals,
behavioral memory representation, blocking reset-array assignments, and the
known synchronized-reset async-use warning. No blocking front-end error was
observed.

## Known blockers entering this phase

1. The current MLP weight header is stale/zero/old-topology data, and the
   available model artifact is not the current 8→128→384→128→1 topology.
2. MLP golden-vector/reference equivalence is therefore BLOCKED.
3. The top-level control path is AXI-like but has not been established as
   strict AXI4-Lite.
4. The actual module-window address decode conflicts with comments describing
   high-bit RLS control addresses.
5. Internal fault/status signals are not all externally propagated, and the
   required status/fault contract is not established.

## Freeze rule

The existing repaired RTL and 17-test regression are the reference baseline.
Any subsequent RTL modification must be recorded in `docs/RTL_CHANGELOG.md`,
classified A/B/C/D, and followed by the complete regression plus new targeted
evidence.

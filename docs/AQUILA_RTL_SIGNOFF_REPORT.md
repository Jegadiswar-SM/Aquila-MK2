# Aquila RTL signoff report

Review date: 2026-09-03. Scope: current worktree, with pre-existing user
changes preserved. Functional RTL was not modified by this review.

## Results

| Check | Status | Evidence/limitation |
|---|---|---|
| RTL hierarchy and source review | IMPLEMENTED | single `rls_dnn_top` hierarchy; ASIC-specific pad source is not used |
| Icarus regression | BLOCKED locally | `scripts/run_iverilog_regression.sh` stops: `iverilog: command not found` |
| Verilator | BLOCKED locally | executable not present |
| Yosys structural check | BLOCKED locally | executable not present |
| Python verification | BLOCKED locally | direct golden runner requires newer Python typing support; pytest is not installed |
| clocks/resets/enables | REVIEWED | one clock; async assertion/sync release; no generated clocks |
| latch/multiple-driver review | REVIEWED | no intentional latch or multi-clock structure identified; lint tool unavailable |
| memory inference | REVIEWED | behavioral 8192×256 wrapper; physical mapping not verified |
| signed/width arithmetic | REVIEW REQUIRED | fixed-point/truncation-sensitive RTL needs Verilator/Genus lint and equivalence |
| X-propagation | REVIEW REQUIRED | simulator/formal X analysis unavailable |
| combinational loops | REVIEW REQUIRED | Yosys unavailable |

Warnings are not silently suppressed. Existing warnings concerning arithmetic,
signedness, incomplete case/default behavior, and behavioral memory are
EXPECTED/REQUIRES REVIEW for ASIC qualification; none is reclassified as a
functional bug without tool evidence. The two current worktree edits are
parser-compatibility declaration moves and remain user-owned.

## Functional boundary

The custom control interface, PLWD `irq_fault`, status response path, reset
qualification, MLP topology, qaa_tanh, and memory wrapper are preserved. This
report does not claim trained-model equivalence: authoritative weights and
golden vectors remain unavailable/blocked as recorded by existing MLP reports.

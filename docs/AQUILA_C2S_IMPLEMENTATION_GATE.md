# AQUILA-MK1 — C2S Implementation Gate

## Gate status

| Gate | Requirement | Status |
|---|---|---|
| G0 environment | tools, licenses, PDK root | FAIL/BLOCKED |
| G1 technology | standard-cell digital views | CONDITIONAL — real FS120 6M1L payload found; provenance/setup not qualified |
| G2 memory | complete SRAM macro and behavior | CONDITIONAL — 8192x32/36 candidates found; GDS provenance, single-port adapter, and MBIST open |
| G3 IO | verified pads/package plan | BLOCKED |
| G4 timing | approved clock/SDC/MMMC | BLOCKED |
| G5 DFT | scan/MBIST methodology | BLOCKED |
| G6 Genus elaboration | explicit top, clean link/check | NOT RUN |
| G7 synthesis | intentional memory mapping | NOT RUN |
| G8 equivalence | Conformal checkpoints | NOT RUN |
| G9 physical | Innovus/P&R | NOT RUN |
| G10 signoff | Tempus/Voltus/PVS/GLS/GDS | NOT RUN |

## Genus GO criteria

Proceed only when C2S supplies verified standard-cell views, a complete SRAM
macro view set, explicit top selection (`aquila_scl180_top` for pad-integrated
scope or `rls_dnn_top` for core-only scope), approved SDC/MMMC, and a clean
technology setup. After elaboration, hard-fail if the active 8192×256 memory is
unresolved or inferred as an unintended flop array.

## Current answer

**CONDITIONAL GO for controlled technology/elaboration qualification; NO-GO
for unrestricted synthesis or physical implementation.** The implementation engineer does not yet have enough verified
technology information to make SRAM, IO, voltage, DFT, timing, or physical
decisions without guessing.

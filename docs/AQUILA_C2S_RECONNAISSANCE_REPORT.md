# AQUILA-MK1 — C2S SCL180 Reconnaissance Report

Review date: 2026-09-03. Scope: read-only reconnaissance. No functional RTL,
PDK collateral, global configuration, or Cadence installation was modified.
No full implementation command was run.

## Decision

**GENUS: CONDITIONAL GO for a controlled C2S run; NO-GO in the current shell.**
The observed machine is `ic312.vit.ac.in`, native Linux
`x86_64`, kernel `4.18.0-477.13.1.el8_8`, with approximately 30 GiB memory and
20 CPUs. The claimed PDK root exists only as a partial `HOTCODE` tree. The
claimed technology directory is missing:

```text
/home/24bvd1009/Desktop/pdk/cdns/sclpdk_v3/ts18scl/v2.0/  MISSING
```

`HOTCODE/.rev_num` contains `ts18scl rev 2.0` and
`HOTCODE/.jazz_amskit_version` contains `ts18scl_20200114_2.0`. This proves the
identity marker, not a complete digital implementation payload.

## What exists

- Analog/custom OA technology and device data under `HOTCODE/amslibs`.
- HSPICE/Spectre device-model collateral under `HOTCODE/models`.
- Calibre DRC/LVS/antenna/dummy-fill runset families.
- RC/XRC collateral for multiple 4/5/6-metal variants.
- Aquila-local technology-neutral ASIC boundary and fail-fast SDC.

## What does not exist in the authoritative `HOTCODE` payload

- Digital standard-cell Liberty/Verilog/LEF/GDS/CDL bundle in `HOTCODE`.
- SRAM or ROM macro in `HOTCODE`.
- IO/pad bundle in `HOTCODE`.
- Modus/DFT collateral or macro-specific MBIST data.
- Quantus/Tempus-ready digital MMMC views.
- These executables are not in `PATH`, but installations are present under
  `/home/install` and require controlled C2S setup/license validation.
- `/usr/sbin/pvs` resolves to Linux `lvm`; Cadence PVS installation exists
  separately under `/home/install/PVS222`.

## Additional real C2S payload

- `/home/24bvd1009/Desktop/stdcell/fs120/6M1L` contains 534-cell Liberty,
  standard-cell and tech LEF, GDS, CDL, and Verilog views with SS/FF timing
  libraries.
- `/home/24bvd1009/pdk-backup-staging/scl180/memories/6M1L` contains complete
  SRAM bundles including `spram_8192_32` and `SPRAM_8192x36`.
- `/home/24bvd1009/pdk-backup-staging/scl180/io/{cio150,cio250,pio520}/6M1L`
  contains real IO physical views; CIO150/CIO250 also contain max/min Liberty.

These staging directories are not yet proven to be one lab-qualified release;
C2S must confirm provenance and cross-library compatibility. They are enough
for a controlled library/link/elaboration qualification gate, not for a
signoff claim.

## Aquila conclusion

The functional core and logical memory contract can remain frozen. SRAM and IO
candidate selections can now be made provisionally, but macro electrical
semantics, provenance/license setup, package scope, DFT integration, and
approved timing/MMMC remain gates. The exact missing evidence is in
the C2S handoff and implementation-gate reports.

## Status

**B. ASIC FRONT-END ARCHITECTURE CLOSED; PDK/CADENCE EXECUTION BLOCKED**

## Final technology baseline

| Item | Baseline decision | Evidence/status |
|---|---|---|
| PDK | `ts18scl`, marker `ts18scl_20200114_2.0` | `HOTCODE` markers are payload-verified; external digital staging provenance is OPEN |
| Standard cells | FS120 6M1L candidate | `/home/24bvd1009/Desktop/stdcell/fs120/6M1L`; SS/FF Liberty, LEF, GDS, CDL, Verilog present; qualification not executed |
| SRAM | 8 × `spram_8192_32` is the interim preferred organization | exact 8192×256 width; single-port/RMW/arbitration and GDS provenance remain gates |
| IO | CIO150 or CIO250 6M1L candidate | physical + Liberty payload; no verified digital pad model or package assignment |
| Clock/reset | one RTL clock domain; preserve `rst_sync` behavior | clock period/uncertainty still project approval items |
| DFT | logic scan plus separately assessed SRAM MBIST | Modus installation found; license, flow, and exact macro support unknown |
| MMMC/RC | construct from FS120 SS/FF and SRAM max/typ/min only after qualification | no integrated MMMC or extracted signoff run |
| Physical verification | existing Calibre/HOTCODE runsets are methodology evidence | DRC/LVS/ERC/antenna not executed |

## Exact blockers

| Blocker | Category | Missing evidence | Resolution owner |
|---|---|---|---|
| staging release compatibility | PDK BLOCKER | C2S confirmation that FS120, SRAM, CIO, and HOTCODE technology data are one qualified release | C2S |
| SRAM physical binding | MEMORY MACRO BLOCKER | macro GDS provenance, exact pin/view consistency, single-port adapter policy, MBIST support | C2S + integration |
| programming/read overlap | ASIC ARCHITECTURE BLOCKER | approved arbitration or a system rule forbidding overlap; 16-bit RMW behavior | project owner + RTL/integration |
| pad ring | IO/PAD BLOCKER | CIO family, digital simulation models, ESD/corners/seal ring/package methodology | C2S + project owner |
| tool execution | CADENCE TOOL BLOCKER | PATH/setup and valid licenses for Genus/Xcelium/Conformal/Modus/Innovus/Tempus/PVS/Quantus/Voltus | C2S |
| timing | PROJECT APPROVAL BLOCKER | approved frequency, IO delay budget, uncertainty, test constraints and MMMC | project owner + STA |
| model | MODEL/DATA BLOCKER | authoritative 8→128→384→128→1 weights and golden vectors | ML owner |

## Final gate decision

The implementation engineer has enough evidence to begin a **controlled C2S
library/elaboration qualification**, but not enough evidence to claim a
technology-frozen Genus run, physical implementation, or tapeout readiness.
The current shell decision is **NO-GO for unrestricted Genus** and
**CONDITIONAL GO after C2S setup, license, provenance, top, SDC, and memory
adapter checks pass**.

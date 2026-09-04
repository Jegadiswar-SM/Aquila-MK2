# AQUILA-MK1 — C2S SRAM Report

## Result

**PHYSICAL SRAM DECISION = PROVISIONALLY CLOSED for candidate selection.** The
authoritative `HOTCODE` tree is empty of macros, but the C2S staging tree
contains complete 6M1L SRAM bundles. Exhaustive filename/content searches of
`/home/24bvd1009/Desktop/pdk/cdns/sclpdk_v3/HOTCODE` found no SRAM, SPRAM,
DPRAM, RAM, ROM, or memory macro payload and no matching Verilog/Liberty/LEF/
GDS/CDL views.

## Aquila logical contract

The active RTL path is:

```text
rls_dnn_top.u_sram -> mlp_weight_sram_wrapper
```

The contract is 8192 rows × 256 bits, 16-bit sequential programming through a
17-bit word address, one-cycle registered read response, and behavioral
read-first/pre-write same-edge collision semantics. The array is not reset or
initialized. The current topology consumes 100,097 16-bit parameters in rows
0–6256; rows 6257–8191 are reserved.

## Candidate table

| Candidate | Depth/width | Views | Status |
|---|---|---|---|
| `spram_8192_32` | 8192×32, single port, 13-bit address | Verilog, max/min/typ Liberty, LEF, CDL | COMPLETE candidate; 6M1L |
| `SPRAM_8192x36` | 8192×36, single port, 13-bit address | Verilog, max/min/typ Liberty, LEF, CDL | COMPLETE candidate; 6M1L/4M1L |

Exact 6M1L evidence:

```text
/home/24bvd1009/pdk-backup-staging/scl180/memories/spram/6M1L/SP_SRAM_spram_8192_32/
/home/24bvd1009/pdk-backup-staging/scl180/memories/spram/6M1L/SPRAM_8192x36/
```

The 32-bit macro LEF size is `1991.800 BY 699.510`; the 36-bit macro LEF
size is `2235.960 BY 699.510`. Observed macro Liberty corners are max
process 1.2 / 125 C / 1.62 V, typ process 1.0 / 25 C / 1.8 V, and min
process 0.8 / -40 C / 1.98 V. Both are single-port, full-word-write
candidates with no observed byte-enable interface. The 32-bit model is
`spram_8192_32` with active-low `CEB`, `CSB`, `OEB`, and `WEB`; the 36-bit
model is `SPRAM_8192x36` with `CE`, `CSB`, `OEB`, and `WEB`.

The candidate directories provide Verilog, LEF, CDL, Liberty, and DB files.
Standalone GDS for each individual SRAM macro was not confirmed in the
candidate directories; macro-to-GDS provenance is therefore still a C2S
gate, and the candidate is not yet a fabrication-ready binding.

## Required C2S decision

The recommended physical organization is **eight `spram_8192_32` macros on
6M1L**, exactly implementing 8192×256. Each macro has active-low `CEB`, `CSB`,
`OEB`, full-word `WEB`, and no 16-bit byte enable. A technology adapter must
perform read-modify-write for each 16-bit programming operation and arbitrate
programming against inference because the macro is single-port. The fallback
is eight `SPRAM_8192x36` macros with 32 unused bits per logical row.

C2S must provide/confirm one real macro or compiler output with depth/width, latency,
collision, write-mask, voltage/PVT, power pins, test pins, and all five views.
Only then may width/depth banking be selected. The interim physical strategy is
`ceil(256 / macro_width)` width banks plus depth banking only when required;
this is not an implementation selection.

Functional weight loading remains separate from MBIST. A full image requires
131,072 16-bit programming cycles unless the host protocol defines a faster
mechanism. No reset-time SRAM clear is assumed.

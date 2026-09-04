# Aquila SCL180 PDK forensic report

Review date: 2026-09-03. Evidence root supplied by the project:
`/home/24bvd1009/Desktop/pdk/cdns/sclpdk_v3/`.

## Executive result

The claimed path `/home/24bvd1009/Desktop/pdk/cdns/sclpdk_v3/ts18scl/v2.0/`
does not exist. The parent contains `HOTCODE/`, whose contents identify
`ts18scl rev 2.0` and `ts18scl_20200114_2.0` in `.rev_num` and
`.jazz_amskit_version`. This is **partial PDK payload**, not a complete
Cadence digital implementation environment.

## Payload manifest

| Category | Observed evidence | Payload status | Required by |
|---|---|---|---|
| Process/device models | `HOTCODE/models/ts18scl/v2.0/hspice/*`, including `ts18sl_scl.lib` with TT/SS/FF/SF/FS device model names | PAYLOAD VERIFIED | circuit modeling only |
| OA technology/device data | `HOTCODE/amslibs/*/cdslibs/ts18scl`, `tech.db`, `techfile.tf`, OA objects | PAYLOAD VERIFIED | Virtuoso/custom/technology setup |
| Calibre DRC/LVS | `HOTCODE/techs/ts18scl*/calibre/.../DRC_*`, `LVS_*` | PAYLOAD VERIFIED as runsets; execution not verified | physical verification |
| Antenna/dummy fill | `ANTENNA_TS18SL_SCL_CALIBRE`, `DUMMYFILL_TS18SL_SCL_CALIBRE` | PAYLOAD VERIFIED as runsets; execution not verified | physical signoff |
| RC/extraction collateral | `SCL18_XRC_*` `.R/.C/.ptf/.xact/.mipt`, `pex/calview.cellmap.*` | PAYLOAD VERIFIED as files; tool compatibility not verified | extraction |
| Metal stack | runset/header names expose 4M1L/5M1L/6M1L and thick-metal T/T3 variants | PAYLOAD VERIFIED as options; project choice OPEN | Innovus/Calibre |
| Standard-cell Liberty | no `.lib` containing verified standard-cell timing library; found `.lib` files are device/HSPICE/Cadence tech files | MISSING | Genus/Tempus |
| Standard-cell LEF | zero `.lef` files under HOTCODE | MISSING | Innovus |
| Standard-cell GDS | zero `.gds`/`.gds2` files under HOTCODE | MISSING | GDS/LVS |
| Standard-cell CDL | zero `.cdl` files under HOTCODE | MISSING | LVS |
| Standard-cell Verilog | only generic/device-related Verilog files; no verified digital cell library | MISSING/UNVERIFIED | Xcelium/Genus |
| IO/pad library | no verified SCL180 pad LEF/GDS/CDL/Liberty set found | MISSING | chip top |
| SRAM macro | no SRAM/SPRAM/DPRAM macro payload or views found | MISSING | memory binding |
| DFT cells/macro support | no Modus cell/memory collateral found | UNKNOWN/MISSING | DFT |
| PVS | `/usr/sbin/pvs` is a symlink to Linux `lvm`, not Cadence PVS | TOOL MISSING | DRC/LVS |

Counts from the exact HOTCODE tree: 0 LEF, 0 GDS/GDS2, 0 CDL, 0 SP, 0 SCS,
0 SV, 102 files ending `.lib`, 2 files ending `.v`, 58 `.db`, and 54 `.tf`.
Filename matches are not treated as cell payloads. No Git-LFS pointer was
found in the inspected PDK tree; absence here is distinct from availability
of digital views.

## Consequence

The supplied tree can support technology inspection and some custom/Calibre
setup work, but cannot support Genus-to-GDS for Aquila. It lacks the standard
cell, IO, and SRAM views needed to elaborate, map, place, route, time, and LVS
the design. The actual C2S machine must provide those views and licensed tools.

No PVT voltage, standard-cell operating condition, IO voltage, SRAM timing,
macro dimensions, or routing rule numeric target is inferred from this kit.

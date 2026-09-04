# AQUILA-MK1 — C2S PDK Manifest

Evidence root:
`/home/24bvd1009/Desktop/pdk/cdns/sclpdk_v3/HOTCODE/`

No Git-LFS pointer signatures were found in the inspected `HOTCODE` tree.
Missing views are therefore classified **MISSING**, not pointer-only.

| Category | Artifact | Exact path/evidence | Payload status | Required by |
|---|---|---|---|---|
| Technology | revision marker | `HOTCODE/.rev_num` | REAL PAYLOAD | identity |
| Technology | AMS kit marker | `HOTCODE/.jazz_amskit_version` | REAL PAYLOAD | identity |
| Device models | HSPICE/Spectre models | `HOTCODE/models/ts18scl/{default,v2.0}` | REAL PAYLOAD | analog/modeling |
| OA technology | Cadence OA/tech data | `HOTCODE/amslibs/*/cdslibs/ts18scl` | REAL PAYLOAD | custom/OA |
| Standard cells | Liberty | no verified digital `.lib` | MISSING | Genus/Tempus |
| Standard cells | Verilog | only generic resistor `verilog.v` | MISSING/UNUSABLE | Genus/Xcelium |
| Standard cells | LEF | 0 `*.lef` files | MISSING | Innovus |
| Standard cells | GDS | 0 `*.gds`/`*.gds2` files | MISSING | GDS/LVS |
| Standard cells | CDL/SPICE | 0 `*.cdl`, `*.sp`, `*.scs` files | MISSING | LVS |
| SRAM/ROM | macro payload | no SRAM/RAM-like files or views | MISSING | memory binding |
| IO/pad | digital pad views | no verified digital IO bundle | MISSING | chip top |
| DFT | scan/MBIST collateral | no Modus/macro test payload | MISSING/UNKNOWN | DFT |
| Extraction | XRC/Calibre RC | `HOTCODE/techs/ts18scl_*`, `HOTCODE/pex` | REAL PAYLOAD; tool compatibility unverified | RC |
| Physical verification | DRC/LVS | `HOTCODE/techs/ts18scl/calibre/*` | REAL RUNSETS; execution unverified | PV |
| Physical verification | antenna/fill | `ANTENNA_TS18SL_SCL_CALIBRE`, `DUMMYFILL_TS18SL_SCL_CALIBRE` | REAL RUNSETS; execution unverified | PV |
| Routing | metal variants | `HOTCODE/techs/ts18scl_4M1L` through `6M1T3` | REAL OPTION DATA; project choice open | Innovus/PV |
| Layer map | digital implementation layer map | no verified Innovus layer map | MISSING/UNKNOWN | Innovus/PV |
| Package | padframe/package examples | none found in inspected tree | MISSING | chip assembly |

File counts in `HOTCODE`: 123,840 total files; 102 files ending `.lib` (device,
HSPICE, or Cadence library text, not verified standard-cell Liberty); 58 `.db`;
54 `.tf`; 2 `.v`; 0 `.lef`, `.gds`, `.gds2`, `.cdl`, `.sp`, `.scs`, or `.sv`.

## External C2S staging payload discovered during reconciliation

The following are outside `HOTCODE` and therefore require C2S owner confirmation
that they are the same qualified release and may be used together. They are
real payloads, not LFS pointers, based on file-content inspection and binary
file identification.

| Category | Artifact | Exact path | Payload status | Version/corner | Required by | Evidence |
|---|---|---|---|---|---|---|
| Standard cells | FS120 6M1L bundle | `/home/24bvd1009/Desktop/stdcell/fs120/6M1L` | REAL PAYLOAD | SS/FF Liberty | Genus/Innovus/Tempus | Liberty, LEF, Verilog, GDS, CDL, DB present |
| Standard cells | SS Liberty | `/home/24bvd1009/Desktop/stdcell/fs120/6M1L/liberty/lib_flow_ss/tsl18fs120_scl_ss.lib` | REAL PAYLOAD | 1.62 V, 125 C, process 1.2 | setup timing | `operating_conditions` inspected |
| Standard cells | FF Liberty | `/home/24bvd1009/Desktop/stdcell/fs120/6M1L/liberty/lib_flow_ff/tsl18fs120_scl_ff.lib` | REAL PAYLOAD | 1.98 V, -40 C, process 0.8 | hold timing | `operating_conditions` inspected |
| SRAM | `spram_8192_32` 6M1L | `/home/24bvd1009/pdk-backup-staging/scl180/memories/spram/6M1L/SP_SRAM_spram_8192_32` | COMPLETE candidate | max/typ/min | memory binding | Verilog, LEF, GDS not separately listed, CDL, Liberty/DB; GDS status requires bundle provenance check |
| SRAM | `SPRAM_8192x36` 6M1L | `/home/24bvd1009/pdk-backup-staging/scl180/memories/spram/6M1L/SPRAM_8192x36` | PARTIAL/COMPLETE candidate | max/typ/min | memory binding | Verilog, LEF, CDL, Liberty/DB present; standalone GDS not found in candidate directory |
| IO | CIO150 6M1L | `/home/24bvd1009/pdk-backup-staging/scl180/io/cio150/6M1L` | PARTIAL | max/min | pad integration | LEF/GDS/CDL/Liberty present; digital Verilog pad model not found |
| IO | CIO250 6M1L | `/home/24bvd1009/pdk-backup-staging/scl180/io/cio250/6M1L` | PARTIAL | max/min | pad integration | LEF/GDS/CDL/Liberty present; digital Verilog pad model not found |
| IO | PIO520SL 6M1L | `/home/24bvd1009/pdk-backup-staging/scl180/io/pio520/6M1L` | PARTIAL | not characterized in observed files | pad physical assembly | LEF/GDS/CDL present; Liberty/Verilog not found |
| Package | sample padframe | `/home/24bvd1009/pdk-backup-staging/scl180/io/sample1_padframe.gds` | REAL PAYLOAD; methodology unknown | unknown | package/pad ring | actual GDS file exists; not proven reusable for Aquila |
| Package | seal-ring collateral | `/home/24bvd1009/pdk-backup-staging/scl180/pdk/cdns/sclpdk_v3/HOTCODE/.../sealrings.html` and `SEALRING_PAD_PDK2020.gds` | REAL PAYLOAD; methodology unknown | unknown | package/pad ring | files inspected; C2S flow ownership not established |
| Cadence | implementation tools | `/home/install/GENUS211`, `/home/install/INNOVUS211`, `/home/install/SSV221`, `/home/install/PVS222`, `/home/install/QUANTUS212`, `/home/install/MODUS221` | INSTALLED; usability unknown | versions partly observed | implementation | executables/install trees found; PATH and license not proven |

**Important qualification:** the staging SRAM entries above do not by themselves
prove a fabrication-qualified macro bundle. In particular, the candidate
directories contain LEF/CDL/Liberty/Verilog, while a standalone GDS view was not
confirmed for each macro. C2S must reconcile macro GDS, CDL, LEF, Liberty, and
Verilog names before physical binding. The earlier `HOTCODE` absence must not be
read as absence from the entire C2S machine.

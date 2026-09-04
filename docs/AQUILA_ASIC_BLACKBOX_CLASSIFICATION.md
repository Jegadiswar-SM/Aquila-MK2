# Aquila ASIC black-box classification

Status: **IMPLEMENTED as a handoff rule; no synthesis classification result
exists locally.**

| Class | Allowed | Current status |
|---|---|---|
| Intentional memory | final approved SCL180 SRAM macro(s) | absent; blocked |
| Intentional IO | final approved SCL180 pad cells through `aquila_scl180_io_bind` | absent; blocked |
| Intentional DFT | approved scan/MBIST technology cells | tool/methodology absent; blocked |
| Aquila functional RTL | every listed RTL module | must resolve; missing module is failure |
| SkyWater IO | `mhda_io_ring` and SkyWater cells | explicitly excluded |
| FPGA primitive | any vendor primitive | prohibited |

C2S must emit a post-elaboration report listing every unresolved/black-box
module, then fail the gate for anything outside the three intentional classes.

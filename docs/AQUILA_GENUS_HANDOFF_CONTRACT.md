# Aquila Genus handoff contract

Status: **prepared; not executed locally.**

| Item | Required value/source |
|---|---|
| Top | `aquila_scl180_top` for integrated handoff; `rls_dnn_top` for core-only debug |
| RTL filelist | `rtl/aad.v`, `affhc.v`, `cbpf_2sos.v`, `fwes.v`, `lat_prof.v`, `mlp_inference.v`, `mlp_weight_sram_wrapper.v`, `plwd.v`, `poly_decim.v`, `ptdl_8stage.v`, `rcim.v`, `rls_dnn_top.v`, `rls_engine.v`, `rst_sync.v` |
| Include paths | `rtl/` and only approved PDK include paths |
| Libraries | approved SCL180 Liberty/physical libraries; absent locally |
| Memory | intentional SCL180 SRAM binding; behavioral wrapper only for contract simulation |
| IO | replace `aquila_scl180_io_bind` body with intentional SCL180 IO binding; SkyWater `mhda_io_ring` excluded |
| Constraints | `constraints/asic/aquila_scl180.sdc` |
| MMMC | approved SCL180 process/voltage/temperature/RC views; fail fast if absent |
| DFT | full-scan/MBIST methodology and inserted-cell requirements from C2S |
| Power | core/IO/macro rails and IR/EM methodology from PDK/C2S |

Required Genus order is READ → ELABORATE → LINK → CHECK DESIGN → CLOCK CHECK
→ MEMORY CHECK → CONSTRAINT CHECK → SYNTHESIS. Do not optimize before clean
elaboration and do not proceed if an intended 8192×256 memory maps to an
unintended flop array.

Allowed black boxes are only intentional SCL180 SRAM, SCL180 IO, and approved
DFT technology cells. Missing Aquila RTL, packages, functional logic, FPGA
primitives, and SkyWater cells are failures.

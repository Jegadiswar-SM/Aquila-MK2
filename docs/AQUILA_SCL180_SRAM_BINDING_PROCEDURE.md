# Aquila SCL180 SRAM binding procedure

Status: **logical architecture CLOSED; SCL180 binding C2S-BLOCKED.** No
macro payload is present locally, and no cell name or electrical property is
assumed.

The selected macro must provide verified Verilog, Liberty, LEF, GDS, CDL,
depth, width, clock/read/write latency, enables and polarities, collision
semantics, power/ground pins, and any test/repair interfaces.

1. Confirm `physical_depth >= 8192` and compose enough banks so
   `composed_width >= 256`.
2. For physical width `W`, choose `B = ceil(256/W)` banks (or an approved
   narrower composition), mapping logical bit `[b*W +: W]` to bank `b`.
3. Preserve logical row address `[12:0]`; do not reinterpret the 16-bit
   programming word address. Lane `wload_addr[3:0]` selects the 16-bit slice
   within the composed row.
4. Implement only the required lane write enables, preserving untouched bits.
   If the macro has no byte/bit write mask, use a read-modify-write mechanism
   with a reviewed latency contract.
5. Match one-cycle read response and the documented same-edge collision
   behavior. Prove this with the adapter test and RTL/netlist equivalence.
6. Connect macro power, ground, test, and repair pins only from the approved
   macro collateral and C2S power plan.
7. Report macro instance count, names, depth, width, total bits, inferred
   memory, flop storage, and all black boxes. Fail if the logical memory is
   implemented as an unintended 8192×256 flop array.

No physical bank count is hard-coded before `W` and the macro semantics are
available.

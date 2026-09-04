# Aquila memory adapter verification

Status: **IMPLEMENTED; execution OPEN in this container.** The self-checking
directed testbench is present, but the current container lacks `iverilog`, so
no local execution result is claimed.

Source: `rtl/mlp_weight_sram_wrapper.v`; test: `tests/asic/memory/tb_mlp_weight_sram_wrapper.v`.

## Cycle contract

The logical store is 8192 rows × 256 bits. A row contains sixteen 16-bit words;
`wload_addr[16:4]` selects the row and `[3:0]` selects the word, while `raddr`
selects a row.

| Operation | Cycle N | Cycle N+1 |
|---|---|---|
| Read | `ren=1`, stable `raddr` | `rvalid=1`, `rdata` is selected row |
| Write | `wload_en=1`, stable address/data | selected 16-bit lane updated |

Writes to different lanes in one row require sixteen cycles; there is no
partial-write mask beyond the selected 16-bit lane. Repeated writes replace
the selected lane. Every 17-bit address is legal for the declared 8192×16
word capacity; there is no representable out-of-range address. Addresses
beyond the 6257 rows used by the trained network are legal reserved storage,
not illegal accesses.

Reset clears `rdata` and `rvalid`; it does not initialize the weight array.
Normal inference and programming mode are distinguished by the external
`wload_en`/`ren` usage; RTL does not add a mode register. The behavioral
implementation's same-edge read/write collision returns the pre-write row
(separate sequential blocks sample old storage before nonblocking writeback).
The physical macro must match this, or the C2S adapter must provide an
equivalent deterministic policy and re-run equivalence/contract tests.

## Directed coverage

The testbench covers single-word write/read, all sixteen lanes, row isolation,
partial programming, repeated writes, same-address collision, reset, and the
lowest/highest legal rows and word addresses. A real SCL180 macro is not used.

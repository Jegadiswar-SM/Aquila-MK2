# Aquila memory architecture decision

## Decision

Freeze the technology-independent logical contract and defer physical
decomposition. The active path is:

```text
rls_dnn_top.u_mlp
  -> mlp_weight_sram_wrapper.u_sram
  -> logical 8192 x 256-bit store
```

This is **ACTIVE**, not an unused abstraction: `rls_dnn_top` wires
`sram_ren/sram_raddr/sram_rdata/sram_rvalid` between `mlp_inference` and
`mlp_weight_sram_wrapper`. `mlp_inference` has no local weight array,
`initial` block, or `mlp_weights.vh` reference. `rtl/mlp_weights.vh` is stale
and outside the active weight path.

## Exact capacity

| Quantity | Value |
|---|---:|
| Topology | 8 → 128 → 384 → 128 → 1 |
| Parameters | 100,097 16-bit words |
| Required bits | 1,601,552 |
| Logical rows | 8,192 |
| Words per row | 16 |
| Total logical words | 131,072 |
| Total logical bits | 2,097,152 |
| Used rows | 6,257 (rows 0–6256) |
| Unused words | 30,975 |
| Unused bits | 495,600 |

The 8192 depth is an explicit address/interface contract, not the minimum
trained-image requirement. The 17-bit programming address maps exactly to
8192×16 words, so no representable programming address is out of range.

## Interim cycle contract

| Cycle | Request | Action | Response |
|---|---|---|---|
| N | `wload_en=1`, `wload_addr`, `wload_data` | update one 16-bit lane in row `wload_addr[16:4]` | no read response |
| N | `ren=1`, `raddr` | sample row address | — |
| N+1 | — | — | `rvalid=1`, `rdata=mem[raddr]` |

The behavioral wrapper has no write enable mask other than the selected lane.
Its same-edge read/write behavior is **read-first/pre-write** as observed from
separate clocked blocks and nonblocking writeback. Reset clears `rdata/rvalid`
but does not clear or initialize memory. This is RTL-model evidence, not
physical-macro evidence.

## Physical recommendation

Recommended interim architecture: width-bank the final SRAM macro(s), preserve
the 13-bit logical row address and lane mapping, and normalize read latency in
an adapter if necessary. The bank count is intentionally `ceil(256/W)` only
after C2S proves a macro width `W` and depth ≥8192. Depth banking is permitted
only if the macro depth is less than 8192 and must preserve exact logical
addressing.

No macro choice is currently possible: **MEMORY MACRO BLOCKER**. The C2S
decision must include Verilog, Liberty, LEF, GDS, CDL, supplies, test pins,
latency, write-mask and collision semantics before binding.

## Initialization and test

The current design does not require power-up initialized SRAM contents in RTL;
weights are externally loaded through `wload_en/wload_addr/wload_data` before a
meaningful MLP transaction. There is no CPU, boot ROM, or software loader in
the active hierarchy. The system owner must approve the host programming
sequence, loading time (up to 131,072 cycles for a full image), and whether
weights persist across reset/power cycles. Functional loading and manufacturing
MBIST are separate requirements.

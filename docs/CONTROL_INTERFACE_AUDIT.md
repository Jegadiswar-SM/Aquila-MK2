# Aquila control-interface audit

## Interface observed in RTL

The top-level ports are 8-bit `AWADDR`/`ARADDR`, 32-bit `WDATA`/`RDATA`,
`AWVALID/AWREADY`, `WVALID/WREADY`, `BVALID/BREADY/BRESP`,
`ARVALID/ARREADY`, and `RVALID/RREADY/RRESP`. There is no `WSTRB` port.

## Requirement comparison

| Requirement | Current RTL | AXI4-Lite requirement | Result |
|---|---|---|---|
| Separate write address channel | Signal exists | AW channel independently handshaked | NON-COMPLIANT: child writes require AWVALID and WVALID together |
| Separate write data channel | Signal exists | W channel independently handshaked | NON-COMPLIANT |
| Write acceptance | Coupled valid condition in children/top control | Each channel may arrive independently; commit after both handshakes | CUSTOM |
| WSTRB | Absent | Required write strobe semantics for AXI4-Lite data lane writes | NON-COMPLIANT |
| B response | One outstanding top response, valid held for BREADY | Response after accepted write, held until BREADY | PARTIALLY COMPLIANT; old acceptance depended on ready/valid timing |
| Independent read address | `ARREADY` blocks outstanding response/pending request | Legal AXI4-Lite one-at-a-time implementation | COMPLIANT for one outstanding request |
| R response stability | Top captures child data and holds RVALID until RREADY | RVALID/RDATA stable while stalled | VERIFIED by `tb_top_read` for current path |
| Read invalid address | Returns zero with OKAY | Deterministic slave response required | CUSTOM; documented as zero/OKAY |
| Reset | Valid/response state reset; raw async assertion and synchronized release | Interface must return idle | VERIFIED in existing reset tests; full protocol reset matrix pending |
| Back-to-back reads | One response must complete before next ARREADY | Legal but not maximum-throughput | CUSTOM single-outstanding behavior |
| Back-to-back writes | Legacy coupled request behavior | Legal only if actual AXI handshakes are honored | NOT VERIFIED as AXI4-Lite |

## Decision

The existing interface is **not AXI4-Lite**. The repository contains no
software or testbench that requires independent AW/W arrival, and adding
`WSTRB` and a new channel-capture microarchitecture would change the external
contract. The interface is therefore retained as an explicitly documented
**Aquila Custom Control Interface**, with a minimum deterministic coupled-write
correction and a canonical address map.

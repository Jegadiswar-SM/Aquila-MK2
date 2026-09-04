# Aquila power and ground architecture

Status: **logical domains CLOSED; electrical implementation C2S-BLOCKED.**

RTL evidence shows one all-digital logic domain: core datapath, control,
reset synchronizer, and logical SRAM are clocked in the same domain. No analog
block, PLL, or explicit voltage-domain crossing exists. The memory is
technology-independent and has no declared physical supply pins.

| Logical resource | Required relationship | Voltage |
|---|---|---|
| Core logic | core digital supply and ground | PDK-dependent, not invented |
| IO ring | IO supply and ground as required by selected pads | PDK-dependent |
| SRAM macro | macro-approved memory supply/ground, possibly separate rails | macro/PDK-dependent |
| Analog | none in current RTL | N/A |
| Test/DFT | only if selected DFT cells/macros require it | C2S-dependent |

Separate core/IO supplies, isolation, and level shifters cannot be decided
without the SCL180 IO/macro voltage rules. No level shifters or isolation cells
are inserted. C2S must define rings, straps, macro connections, standard-cell
rails, vias, decoupling, and EM/IR analysis from real design rules.

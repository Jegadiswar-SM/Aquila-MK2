# Aquila DFT architecture

Status: **architecture recommendation CLOSED; insertion and coverage
C2S-BLOCKED.** No Modus or equivalent insertion result is available locally.

RTL has one clock domain, active-low asynchronous reset assertion, resettable
pipeline/state registers, adaptive state, and a large logical SRAM. There are
no functional test, scan, scan-enable, scan-clock, scan-in, scan-out, or
memory-test ports in `rls_dnn_top`. `clk_gate_en` is not a scan control.

## Recommendation

Use full scan of all synthesizable standard-cell flops, with the reset
synchronizer and reset behavior handled according to the selected library DFT
rules. Exclude or specially constrain SRAM bitcells; provide the selected
macro's MBIST/test interface if it exists. At minimum the C2S flow shall
define scan clock/test enable access, wrapper-level test mode, stuck-at and
transition ATPG, chain count/length, reset controllability, and test clocks.

The SRAM must be checked for MBIST, direct test mode, scan access, repair and
redundancy. These features are **C2S PDK/macro dependent** and no coverage is
claimed until documented macro collateral and ATPG reports exist.

DFT insertion must remain outside functional RTL until the tool methodology,
cell library, pad access, and memory test strategy are confirmed. The inserted
test wrapper must preserve the functional top interface and be included in
equivalence, gate simulation, STA, and final LVS netlist intent.

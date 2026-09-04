# Aquila clock/reset architecture

Status: **CLOSED at RTL; timing qualification is C2S/PDK-dependent.**

## Evidence

The reviewed top is `rls_dnn_top`. All synthesizable sequential logic found in
the Aquila hierarchy is clocked by its single `clk` input. There are no derived
clocks, clock muxes, asynchronous data clocks, or clock-domain crossings in
the RTL. `sample_enable` is a synchronous enable/strobe, not a clock.

| Item | Contract | Status |
|---|---|---|
| Clock source | external top-level `clk` | CLOSED |
| Clock domains | one domain: `clk` | CLOSED |
| Clock period | required parameter `AQUILA_CLOCK_PERIOD_NS` | OPEN pending approval |
| Enables | sample admission, pipeline valid enables, `sample_enable`, `srst` | CLOSED |
| Clock gating | none inserted; `clk_gate_en` is AAD status/output only | CLOSED |
| Reset type | asynchronous assertion, active-low | CLOSED |
| Reset release | `rst_sync` two-flop synchronous deassertion | CLOSED at RTL |
| CDC | none identified | CLOSED by RTL inspection; CDC tool unavailable |

The raw `rst_n` drives the synchronizer assertion input. Internal logic uses
the synchronized reset (`rst_n_sync`) and, where applicable, the PLWD pipeline
soft reset. PLWD soft reset is a synchronous pipeline recovery event and is not
a clock. Adaptive state intentionally has different soft-reset retention as
specified by the functional RTL.

The output `clk_gate_en` is connected from AAD as an activity/status signal.
It does not drive any `always` block clock edge. Physical clock gating, if later
required, is a C2S physical-design decision using approved gating cells and
must not be implemented by changing this RTL contract.

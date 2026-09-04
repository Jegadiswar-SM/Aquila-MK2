# Aquila clock/reset decision

## Frozen RTL architecture

There is one sequential clock domain: top-level `clk`. All inspected
`always @(posedge clk...)` blocks in `rtl/` use this clock. `sample_enable`,
decimation enables, valid signals, and PLWD recovery are enables/control
events, not clocks. No generated clock, clock mux, asynchronous data clock, or
CDC synchronizer other than reset synchronization was found.

`clk_gate_en` is assigned from `aad_clk_gate_en` and exits the chip. It is not
used as a clock in the functional hierarchy. It is therefore status/advisory
clock-gating intent, not implemented clock gating.

## Reset

`rst_sync` uses two flops with asynchronous active-low assertion and
synchronous deassertion. `rls_dnn_top` feeds `rst_n_sync` to child logic;
top-level state uses raw `rst_n` for assertion and qualifies release with
`rst_n_sync`. PLWD `pipeline_srst` is a synchronous recovery reset and is not a
clock. The SRAM data array is not reset.

## Frequency decision

| Quantity | Decision |
|---|---|
| Required minimum | UNKNOWN — system specification does not establish a minimum |
| Recommended implementation target | 50 MHz / 20 ns, CONDITIONAL engineering target only |
| Signoff target | OPEN — project owner approval required |
| Evidence | 8 kHz sample rate gives 6250 cycles/sample at 50 MHz; observed zero-memory MLP schedule is about 12.2k cycles, so throughput requires transaction spacing/backpressure behavior rather than one result every sample at 50 MHz |
| Conflicting evidence | README/synthesis collateral also states 100 MHz/10 ns; no approved timing requirement resolves the conflict |

The 50 MHz recommendation is not a verified product requirement and must not
be treated as frozen SDC. The current fail-fast SDC requires
`AQUILA_CLOCK_PERIOD_NS` and approved IO timing. No false/multicycle exception
is justified by the RTL review.

## Gating recommendation

Omit physical clock gating for the first academic implementation. Keep the
existing `clk_gate_en` output as functional/status behavior. Inserting ICGs is
an optional physical optimization with scan, CTS, gating-check, and reset
risks; it requires C2S library evidence and project approval.

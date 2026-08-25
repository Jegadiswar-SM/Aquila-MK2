# Aquila fault and status specification

## External contract

The only top-level fault output implemented by the current RTL is
`irq_fault`, driven by PLWD. `clk_gate_en` is the AAD activity-derived output;
it is not a fault indicator. No RCIM, CBPF, AAD, AFFHC, or RLS debug signal is
currently exported through the top-level control read path.

| Signal | Source | Meaning | Active level | Sticky? | Clear method | External visibility |
|---|---|---|---|---|---|---|
| `plwd_pipeline_srst` | PLWD | Eight-cycle datapath recovery reset | 1 | No | Automatic FSM completion | Internal only |
| `irq_fault` | PLWD | Fault notification after recovery | 1 pulse | No; cleared in next IDLE cycle or PLWD read-clear action | Automatic next IDLE / read offset 0 | Top-level output |
| `fault_type_reg` | PLWD | 01 no-valid timeout; 10 repeated output | Encoded | Yes until clear/reset | Write 0x6C or reset | Read 0x60 |
| `fault_sample_cnt` | PLWD | Accepted output-transfer count captured at fault | Encoded count | Yes until reset | Reset only in current RTL | Read 0x64 |
| `fault_count_reg` | PLWD | Number of logged recovery events | Encoded count | Yes until clear/reset | Write 0x6C or reset | Read 0x68 |
| `ref_channel_fault` | RCIM | Correlation below threshold persistently | 1 | Yes with 16-sample recovery hysteresis | Automatic valid-sample recovery/reset | Internal only |
| `clip_s1`, `clip_s2` | CBPF | Section intermediate clipping indication | Pulse/status from filter | No | New valid/reset | Internal only |
| `signal_active` | AAD | Acoustic activity state | 1 | State | Energy-based deassert/reset | Internal only |
| `clk_gate_en` | AAD | Registered activity-derived gate-enable output | 1 | State/output | AAD state/reset | Top-level output |

## Fault policy

The existing external behavior is preserved: only PLWD generates the external
interrupt. RCIM fault remains an internal datapath safety mux that substitutes
zero reference data; it is not silently promoted into `irq_fault`, because
that would change interrupt behavior without an established system contract.

PLWD fault priority is deterministic in the current FSM: a stall fault is
captured if present; otherwise a stuck-output fault is captured. The fault
type/count/sample fields are read through the PLWD register window. Fault clear
clears IRQ/type/count in the current implementation; the sample-count log is
retained until reset.

This specification distinguishes current verified visibility from signals that
remain internal. Any future requirement to expose RCIM/CBPF/AAD status must be
an explicit interface change and receive new software and regression evidence.

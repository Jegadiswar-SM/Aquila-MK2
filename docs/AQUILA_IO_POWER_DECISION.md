# Aquila IO and power decision

## IO decision

Use `aquila_scl180_top` and replace only the body of
`aquila_scl180_io_bind` with approved SCL180 pads. The current functional
interface has 32 input/control/data-related signal bits plus outputs, with no
functional bidirectional bus. Exact counts from `rls_dnn_top` are:

| Group | Direction/width |
|---|---:|
| `clk`, `rst_n`, `sample_enable`, `wload_en` | 4 inputs |
| `wload_addr`, `wload_data` | 17+16 input bits |
| AXI-stream input (`s_axis_tdata`, `s_axis_tvalid`) | 33 input bits |
| AXI-stream handshake/output (`s_axis_tready`, `m_axis_tdata`, `m_axis_tvalid`, `m_axis_tready`) | 19 output/input bits |
| Custom control inputs | 8+1+32+1+1+8+1+1 = 53 bits |
| Custom control outputs | 1+1+2+1+1+32+2+1 = 41 bits |
| `clk_gate_en`, `irq_fault` | 2 outputs |

There are no scan, test-mode, MBIST, or bidirectional functional ports in RTL.
The pad ring therefore needs digital input/output pads, clock/reset treatment,
power/ground pads, and any DFT pads added by the confirmed methodology.

## Power decision

Logical domains are one all-digital core plus external IO and eventual SRAM
macro supply resources. Actual voltage values are **UNKNOWN — C2S REQUIRED**.
The PDK device model file documents 1.8 V and 3.3 V device classes, but that
does not establish the selected standard-cell or IO operating voltage.

| Resource | Decision |
|---|---|
| Core voltage | UNKNOWN — C2S REQUIRED |
| IO voltage | UNKNOWN — C2S REQUIRED |
| SRAM voltage | UNKNOWN — macro required |
| Analog domain | none in functional RTL |
| Isolation/level shifting | none inserted; decide from approved voltage plan |
| Power pads/ring | count and names C2S/package dependent |
| Ground pads/ring | count and names C2S/package dependent |

No core/IO separation, level shifters, isolation, ring dimensions, strap
widths, via arrays, decap, tap, endcap, or EM limits are invented.

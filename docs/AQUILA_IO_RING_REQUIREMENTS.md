# Aquila IO and ring requirements

Status: **logical IO list CLOSED; SCL180 pad selection and ring closure
C2S-BLOCKED.** `rtl/mhda_io_ring.v` is SkyWater-specific and is excluded
from any SCL180 manifest.

## Signal pads

| Signal group | Direction | Role | Expected pad class |
|---|---|---|---|
| `clk` | input | primary clock | digital input, clock-capable if required by PDK |
| `rst_n` | input | active-low async reset assertion | digital input with approved reset treatment |
| `sample_enable` | input | synchronous sample strobe | digital input |
| `wload_en`, `wload_addr[16:0]`, `wload_data[15:0]` | input | sequential weight programming | digital inputs |
| `s_axis_tdata[31:0]`, `s_axis_tvalid` | input | sample stream | digital inputs |
| `s_axis_tready` | output | stream backpressure | digital output |
| `m_axis_tdata[15:0]`, `m_axis_tvalid` | output | result stream | digital outputs |
| `m_axis_tready` | input | result backpressure | digital input |
| `s_axi_awaddr[7:0]`, `s_axi_awvalid`, `s_axi_wdata[31:0]`, `s_axi_wvalid`, `s_axi_bready`, `s_axi_araddr[7:0]`, `s_axi_arvalid`, `s_axi_rready` | input | custom control request/handshake | digital inputs |
| `s_axi_awready`, `s_axi_wready`, `s_axi_bresp[1:0]`, `s_axi_bvalid`, `s_axi_arready`, `s_axi_rdata[31:0]`, `s_axi_rresp[1:0]`, `s_axi_rvalid` | output | custom control response/handshake | digital outputs |
| `clk_gate_en`, `irq_fault` | output | activity/status and fault indication | digital outputs |

There are no bidirectional functional data signals in `rls_dnn_top`.
Power/ground pads are separate ring resources, not RTL functional ports.

## Ring resources

The final ring requires input pads, output pads, primary clock and reset pad
treatment, core power pads, IO power pads, core grounds, IO grounds, and any
DFT pads required by the selected scan/memory methodology. Test pads are not
present in the current functional top and must not be invented; they are added
only as a C2S DFT wrapper decision.

Pad cell names, voltage options, drive strengths, slew, ESD structures, pad
ordering, corner cells, and power-pad count remain PDK-dependent.

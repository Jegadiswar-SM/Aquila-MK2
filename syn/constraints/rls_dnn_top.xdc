## =============================================================================
## Constraints : rls_dnn_top.xdc
## Target      : Xilinx 7-Series / UltraScale
## Clock       : 100 MHz  (10.000 ns period)
## SPDX-License-Identifier: Apache-2.0
## =============================================================================

## -- Primary Clock --------------------------------------------------------------
create_clock -period 10.000 -name clk -waveform {0.000 5.000} [get_ports clk]

## -- Input Delays (AXI-S slave, relative to clk) --------------------------------
set_input_delay -clock clk -max 2.000 [get_ports {s_axis_tdata[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {s_axis_tdata[*]}]
set_input_delay -clock clk -max 2.000 [get_ports s_axis_tvalid]
set_input_delay -clock clk -min 0.500 [get_ports s_axis_tvalid]
set_input_delay -clock clk -max 2.000 [get_ports m_axis_tready]
set_input_delay -clock clk -min 0.500 [get_ports m_axis_tready]
set_input_delay -clock clk -max 2.000 [get_ports sample_enable]
set_input_delay -clock clk -min 0.500 [get_ports sample_enable]
set_input_delay -clock clk -max 2.000 [get_ports rst_n]
set_input_delay -clock clk -min 0.500 [get_ports rst_n]

## -- Input Delays (AXI4-Lite) ---------------------------------------------------
set_input_delay -clock clk -max 2.000 [get_ports {s_axi_awaddr[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {s_axi_awaddr[*]}]
set_input_delay -clock clk -max 2.000 [get_ports s_axi_awvalid]
set_input_delay -clock clk -min 0.500 [get_ports s_axi_awvalid]
set_input_delay -clock clk -max 2.000 [get_ports {s_axi_wdata[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {s_axi_wdata[*]}]
set_input_delay -clock clk -max 2.000 [get_ports s_axi_wvalid]
set_input_delay -clock clk -min 0.500 [get_ports s_axi_wvalid]
set_input_delay -clock clk -max 2.000 [get_ports {s_axi_araddr[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {s_axi_araddr[*]}]
set_input_delay -clock clk -max 2.000 [get_ports s_axi_arvalid]
set_input_delay -clock clk -min 0.500 [get_ports s_axi_arvalid]
set_input_delay -clock clk -max 2.000 [get_ports s_axi_bready]
set_input_delay -clock clk -min 0.500 [get_ports s_axi_bready]
set_input_delay -clock clk -max 2.000 [get_ports s_axi_rready]
set_input_delay -clock clk -min 0.500 [get_ports s_axi_rready]

## -- Output Delays (AXI-S master) -----------------------------------------------
set_output_delay -clock clk -max 2.000 [get_ports {m_axis_tdata[*]}]
set_output_delay -clock clk -min -0.500 [get_ports {m_axis_tdata[*]}]
set_output_delay -clock clk -max 2.000 [get_ports m_axis_tvalid]
set_output_delay -clock clk -min -0.500 [get_ports m_axis_tvalid]
set_output_delay -clock clk -max 2.000 [get_ports s_axis_tready]
set_output_delay -clock clk -min -0.500 [get_ports s_axis_tready]

## -- Output Delays (AXI4-Lite) --------------------------------------------------
set_output_delay -clock clk -max 2.000 [get_ports s_axi_awready]
set_output_delay -clock clk -min -0.500 [get_ports s_axi_awready]
set_output_delay -clock clk -max 2.000 [get_ports s_axi_wready]
set_output_delay -clock clk -min -0.500 [get_ports s_axi_wready]
set_output_delay -clock clk -max 2.000 [get_ports {s_axi_bresp[*]}]
set_output_delay -clock clk -min -0.500 [get_ports {s_axi_bresp[*]}]
set_output_delay -clock clk -max 2.000 [get_ports s_axi_bvalid]
set_output_delay -clock clk -min -0.500 [get_ports s_axi_bvalid]
set_output_delay -clock clk -max 2.000 [get_ports {s_axi_rdata[*]}]
set_output_delay -clock clk -min -0.500 [get_ports {s_axi_rdata[*]}]
set_output_delay -clock clk -max 2.000 [get_ports s_axi_rvalid]
set_output_delay -clock clk -min -0.500 [get_ports s_axi_rvalid]

## -- Top-level outputs ----------------------------------------------------------
set_output_delay -clock clk -max 2.000 [get_ports clk_gate_en]
set_output_delay -clock clk -min -0.500 [get_ports clk_gate_en]
set_output_delay -clock clk -max 2.000 [get_ports irq_fault]
set_output_delay -clock clk -min -0.500 [get_ports irq_fault]

## -- DSP48 Packing Hint ---------------------------------------------------------
set_property KEEP_HIERARCHY SOFT [get_cells {u_rls u_mlp u_cbpf u_affhc u_aad u_rcim}]

## -- False Paths (reset is multicycle, async assert / sync deassert) ------------
set_false_path -from [get_ports rst_n]

## -- Max Fanout to help timing --------------------------------------------------
set_property MAX_FANOUT 16 [get_nets {u_mlp/s0_valid}]
set_property MAX_FANOUT 16 [get_nets {u_mlp/s1_valid}]

## =============================================================================

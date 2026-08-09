# =============================================================================
# Constraints : rls_dnn_top.sdc
# Target      : sky130 / General ASIC Synthesis
# Clock       : 100 MHz (10.000 ns period)
# SPDX-License-Identifier: Apache-2.0
# =============================================================================

# Define clock (100 MHz) with 5% jitter/skew allowance (0.5ns)
create_clock -name clk -period 10.000 [get_ports pad_clk]
set_clock_uncertainty 0.500 [get_clocks clk]

# Input delays (relative to clk edge, max = 2.0ns, min = 0.5ns)
set_input_delay -clock clk -max 2.000 [get_ports {pad_s_axis_tdata[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {pad_s_axis_tdata[*]}]
set_input_delay -clock clk -max 2.000 [get_ports pad_s_axis_tvalid]
set_input_delay -clock clk -min 0.500 [get_ports pad_s_axis_tvalid]
set_input_delay -clock clk -max 2.000 [get_ports pad_m_axis_tready]
set_input_delay -clock clk -min 0.500 [get_ports pad_m_axis_tready]
set_input_delay -clock clk -max 2.000 [get_ports pad_sample_enable]
set_input_delay -clock clk -min 0.500 [get_ports pad_sample_enable]

# Weight programming interface input delays
set_input_delay -clock clk -max 2.000 [get_ports pad_wload_en]
set_input_delay -clock clk -min 0.500 [get_ports pad_wload_en]
set_input_delay -clock clk -max 2.000 [get_ports {pad_wload_addr[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {pad_wload_addr[*]}]
set_input_delay -clock clk -max 2.000 [get_ports {pad_wload_data[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {pad_wload_data[*]}]

# AXI4-Lite input delays
set_input_delay -clock clk -max 2.000 [get_ports {pad_s_axi_awaddr[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {pad_s_axi_awaddr[*]}]
set_input_delay -clock clk -max 2.000 [get_ports pad_s_axi_awvalid]
set_input_delay -clock clk -min 0.500 [get_ports pad_s_axi_awvalid]
set_input_delay -clock clk -max 2.000 [get_ports {pad_s_axi_wdata[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {pad_s_axi_wdata[*]}]
set_input_delay -clock clk -max 2.000 [get_ports pad_s_axi_wvalid]
set_input_delay -clock clk -min 0.500 [get_ports pad_s_axi_wvalid]
set_input_delay -clock clk -max 2.000 [get_ports {pad_s_axi_araddr[*]}]
set_input_delay -clock clk -min 0.500 [get_ports {pad_s_axi_araddr[*]}]
set_input_delay -clock clk -max 2.000 [get_ports pad_s_axi_arvalid]
set_input_delay -clock clk -min 0.500 [get_ports pad_s_axi_arvalid]
set_input_delay -clock clk -max 2.000 [get_ports pad_s_axi_bready]
set_input_delay -clock clk -min 0.500 [get_ports pad_s_axi_bready]
set_input_delay -clock clk -max 2.000 [get_ports pad_s_axi_rready]
set_input_delay -clock clk -min 0.500 [get_ports pad_s_axi_rready]

# Output delays (max = 2.0ns, min = -0.5ns)
set_output_delay -clock clk -max 2.000 [get_ports {pad_m_axis_tdata[*]}]
set_output_delay -clock clk -min -0.500 [get_ports {pad_m_axis_tdata[*]}]
set_output_delay -clock clk -max 2.000 [get_ports pad_m_axis_tvalid]
set_output_delay -clock clk -min -0.500 [get_ports pad_m_axis_tvalid]
set_output_delay -clock clk -max 2.000 [get_ports pad_s_axis_tready]
set_output_delay -clock clk -min -0.500 [get_ports pad_s_axis_tready]

# AXI4-Lite output delays
set_output_delay -clock clk -max 2.000 [get_ports pad_s_axi_awready]
set_output_delay -clock clk -min -0.500 [get_ports pad_s_axi_awready]
set_output_delay -clock clk -max 2.000 [get_ports pad_s_axi_wready]
set_output_delay -clock clk -min -0.500 [get_ports pad_s_axi_wready]
set_output_delay -clock clk -max 2.000 [get_ports {pad_s_axi_bresp[*]}]
set_output_delay -clock clk -min -0.500 [get_ports {pad_s_axi_bresp[*]}]
set_output_delay -clock clk -max 2.000 [get_ports pad_s_axi_bvalid]
set_output_delay -clock clk -min -0.500 [get_ports pad_s_axi_bvalid]
set_output_delay -clock clk -max 2.000 [get_ports {pad_s_axi_rdata[*]}]
set_output_delay -clock clk -min -0.500 [get_ports {pad_s_axi_rdata[*]}]
set_output_delay -clock clk -max 2.000 [get_ports pad_s_axi_rvalid]
set_output_delay -clock clk -min -0.500 [get_ports pad_s_axi_rvalid]

# Gating & Interrupt outputs
set_output_delay -clock clk -max 2.000 [get_ports pad_clk_gate_en]
set_output_delay -clock clk -min -0.500 [get_ports pad_clk_gate_en]
set_output_delay -clock clk -max 2.000 [get_ports pad_irq_fault]
set_output_delay -clock clk -min -0.500 [get_ports pad_irq_fault]

# Async Reset - set as false path since it is asynchronously asserted
# Reset synchronizer (2FF) handles the synchronous deassertion safely
set_false_path -from [get_ports pad_rst_n]

# Disable timing checks on inactive pins during operation
set_case_analysis 0 [get_ports pad_wload_en]

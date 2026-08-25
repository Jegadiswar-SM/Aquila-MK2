`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// Control contract regression for the Aquila Custom Control Interface.
// This intentionally verifies coupled writes, canonical byte offsets,
// invalid-write responses, and the absence of independent AW/W acceptance.
module tb_control_plane;
    reg clk, rst_n, sample_enable;
    reg wload_en;
    reg [16:0] wload_addr;
    reg [15:0] wload_data;
    reg [31:0] s_axis_tdata;
    reg s_axis_tvalid;
    wire s_axis_tready;
    wire [15:0] m_axis_tdata;
    wire m_axis_tvalid;
    reg m_axis_tready;
    reg [7:0] s_axi_awaddr, s_axi_araddr;
    reg s_axi_awvalid, s_axi_wvalid, s_axi_arvalid;
    reg [31:0] s_axi_wdata;
    wire s_axi_awready, s_axi_wready;
    wire [1:0] s_axi_bresp, s_axi_rresp;
    wire s_axi_bvalid, s_axi_rvalid, s_axi_arready;
    reg s_axi_bready, s_axi_rready;
    wire [31:0] s_axi_rdata;
    wire clk_gate_en, irq_fault;
    integer failures;

    rls_dnn_top dut (.*);

    initial clk = 1'b0;
    always #5 clk = ~clk;

    task automatic coupled_write;
        input [7:0] addr;
        input [31:0] data;
        input [1:0] expected_resp;
        begin
            @(negedge clk);
            s_axi_awaddr  = addr;
            s_axi_wdata   = data;
            s_axi_awvalid = 1'b1;
            s_axi_wvalid  = 1'b1;
            wait (s_axi_awready && s_axi_wready);
            @(posedge clk);
            #1;
            if (!s_axi_bvalid || s_axi_bresp !== expected_resp) begin
                $display("FAIL write addr=%h bvalid=%b bresp=%b expected=%b",
                         addr, s_axi_bvalid, s_axi_bresp, expected_resp);
                failures = failures + 1;
            end
            @(negedge clk);
            s_axi_awvalid = 1'b0;
            s_axi_wvalid  = 1'b0;
            @(posedge clk);
            #1;
            if (s_axi_bvalid) begin
                $display("FAIL BVALID did not clear addr=%h", addr);
                failures = failures + 1;
            end
        end
    endtask

    initial begin
        failures = 0;
        rst_n = 1'b0;
        sample_enable = 1'b0;
        wload_en = 1'b0; wload_addr = 0; wload_data = 0;
        s_axis_tdata = 0; s_axis_tvalid = 1'b0;
        m_axis_tready = 1'b1;
        s_axi_awaddr = 0; s_axi_awvalid = 1'b0;
        s_axi_wdata = 0; s_axi_wvalid = 1'b0;
        s_axi_bready = 1'b1;
        s_axi_araddr = 0; s_axi_arvalid = 1'b0;
        s_axi_rready = 1'b1;

        repeat (5) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;
        wait (dut.rst_n_sync);

        // AW-only and W-only requests must not update a coupled register.
        @(negedge clk);
        s_axi_awaddr = 8'hA0;
        s_axi_wdata = 32'h00001234;
        s_axi_awvalid = 1'b1;
        @(posedge clk);
        #1;
        if (s_axi_bvalid || dut.rls_leak_factor !== 16'h7FE0) begin
            $display("FAIL AW-only request was accepted");
            failures = failures + 1;
        end
        @(negedge clk);
        s_axi_awvalid = 1'b0;
        s_axi_wvalid = 1'b1;
        @(posedge clk);
        #1;
        if (s_axi_bvalid || dut.rls_leak_factor !== 16'h7FE0) begin
            $display("FAIL W-only request was accepted");
            failures = failures + 1;
        end
        @(negedge clk);
        s_axi_wvalid = 1'b0;

        // Canonical windows and previously inaccessible AFFHC offset.
        coupled_write(8'h00, 32'h00001111, 2'b00);
        coupled_write(8'h04, 32'h00002222, 2'b00);
        coupled_write(8'h08, 32'h00003333, 2'b00);
        coupled_write(8'h0C, 32'h00000044, 2'b00);
        coupled_write(8'h10, 32'h00000123, 2'b00);
        if (dut.u_affhc.lambda_slow !== 16'h1111 ||
            dut.u_affhc.lambda_mid !== 16'h2222 ||
            dut.u_affhc.lambda_fast !== 16'h3333 ||
            dut.u_affhc.threshold_up_reg !== 16'h0044 ||
            dut.u_affhc.threshold_down_reg !== 16'h0123) begin
            $display("FAIL AFFHC register write/readback state");
            failures = failures + 1;
        end
        coupled_write(8'h20, 32'h00000003, 2'b00);
        if (dut.u_aad.ratio_shift_reg !== 4'h3) begin
            $display("FAIL AAD ratio write did not apply");
            failures = failures + 1;
        end
        coupled_write(8'h40, 32'h00000001, 2'b00);
        if (dut.u_cbpf.bypass_reg !== 1'b1) begin
            $display("FAIL CBPF bypass write did not apply");
            failures = failures + 1;
        end
        coupled_write(8'h80, 32'h00004567, 2'b00);
        if (dut.u_rcim.corr_threshold !== 16'h4567) begin
            $display("FAIL RCIM threshold write did not apply");
            failures = failures + 1;
        end
        coupled_write(8'hA0, 32'h00005678, 2'b00);
        if (dut.rls_leak_factor !== 16'h5678) begin
            $display("FAIL RLS leak-factor write did not apply");
            failures = failures + 1;
        end
        coupled_write(8'hA4, 32'h00006789, 2'b00);
        coupled_write(8'hA8, 32'h00000004, 2'b00);
        if (dut.fwes_alpha_reg !== 16'h6789 || dut.decim_ratio !== 3'b100) begin
            $display("FAIL RLS/FWES/decimation writes did not apply");
            failures = failures + 1;
        end

        // LATPROF is read-only and the reserved window is invalid for writes.
        coupled_write(8'hC0, 32'h00000001, 2'b10);
        coupled_write(8'hE0, 32'h00000001, 2'b10);

        // Reads of unimplemented configuration registers are deterministic
        // zero/OKAY rather than stale child data.
        @(negedge clk);
        s_axi_araddr = 8'hA0;
        s_axi_arvalid = 1'b1;
        wait (s_axi_arready);
        @(posedge clk);
        #1;
        @(negedge clk);
        s_axi_arvalid = 1'b0;
        wait (s_axi_rvalid);
        if (s_axi_rdata !== 32'd0 || s_axi_rresp !== 2'b00) begin
            $display("FAIL unimplemented read data=%h resp=%b", s_axi_rdata, s_axi_rresp);
            failures = failures + 1;
        end
        @(posedge clk);

        // The final LATPROF interval and free-counter registers are in the
        // documented read-only extension at 0xE4/0xE8.
        force dut.u_latprof.lat_total = 32'h12345678;
        @(negedge clk);
        s_axi_araddr = 8'hE4;
        s_axi_arvalid = 1'b1;
        wait (s_axi_arready);
        @(posedge clk);
        #1;
        @(negedge clk);
        s_axi_arvalid = 1'b0;
        wait (s_axi_rvalid);
        if (s_axi_rdata !== 32'h12345678) begin
            $display("FAIL LATPROF total read data=%h", s_axi_rdata);
            failures = failures + 1;
        end
        @(posedge clk);
        release dut.u_latprof.lat_total;

        force dut.u_latprof.free_cnt = 32'h87654321;
        @(negedge clk);
        s_axi_araddr = 8'hE8;
        s_axi_arvalid = 1'b1;
        wait (s_axi_arready);
        @(posedge clk);
        #1;
        @(negedge clk);
        s_axi_arvalid = 1'b0;
        wait (s_axi_rvalid);
        if (s_axi_rdata !== 32'h87654321) begin
            $display("FAIL LATPROF free-counter read data=%h", s_axi_rdata);
            failures = failures + 1;
        end
        @(posedge clk);
        release dut.u_latprof.free_cnt;

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        if (failures != 0)
            $fatal(1, "control-plane test failed");
        $finish;
    end
endmodule

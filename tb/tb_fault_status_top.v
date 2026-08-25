`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

// Verifies the documented external PLWD fault/status contract. The internal
// fault source is forced only to make the recovery path deterministic without
// waiting for an unrelated datapath failure.
module tb_fault_status_top;
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

    task automatic read_reg;
        input [7:0] addr;
        output [31:0] data;
        begin
            @(negedge clk);
            s_axi_araddr = addr;
            s_axi_arvalid = 1'b1;
            wait (s_axi_arready);
            @(posedge clk);
            @(negedge clk);
            s_axi_arvalid = 1'b0;
            wait (s_axi_rvalid);
            #1 data = s_axi_rdata;
            @(posedge clk);
        end
    endtask

    task automatic clear_fault;
        begin
            @(negedge clk);
            s_axi_awaddr = 8'h6C;
            s_axi_wdata = 32'h1;
            s_axi_awvalid = 1'b1;
            s_axi_wvalid = 1'b1;
            wait (s_axi_awready && s_axi_wready);
            @(posedge clk);
            #1;
            if (!s_axi_bvalid || s_axi_bresp !== 2'b00) begin
                $display("FAIL fault-clear response valid=%b resp=%b",
                         s_axi_bvalid, s_axi_bresp);
                failures = failures + 1;
            end
            @(negedge clk);
            s_axi_awvalid = 1'b0;
            s_axi_wvalid = 1'b0;
            @(posedge clk);
        end
    endtask

    reg [31:0] rd;
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

        force dut.u_plwd.pipeline_stall_fault = 1'b1;
        // Keep the source asserted through IDLE -> FAULT_DETECT and the
        // following capture edge; releasing immediately after state entry
        // would make the FSM's documented fallback type (stuck output) win.
        repeat (2) @(posedge clk);
        release dut.u_plwd.pipeline_stall_fault;
        wait (irq_fault);
        if (!irq_fault) begin
            $display("FAIL watchdog IRQ was not generated");
            failures = failures + 1;
        end

        read_reg(8'h60, rd);
        if (rd[1:0] !== 2'b01) begin
            $display("FAIL fault type=%h expected stall=1", rd);
            failures = failures + 1;
        end
        read_reg(8'h68, rd);
        if (rd[7:0] == 8'd0) begin
            $display("FAIL fault count did not increment");
            failures = failures + 1;
        end

        clear_fault();
        read_reg(8'h60, rd);
        if (rd[1:0] !== 2'b00) begin
            $display("FAIL fault type did not clear: %h", rd);
            failures = failures + 1;
        end
        read_reg(8'h68, rd);
        if (rd[7:0] !== 8'd0) begin
            $display("FAIL fault count did not clear: %h", rd);
            failures = failures + 1;
        end

        if (failures == 0)
            $display("RESULT: PASS");
        else
            $display("RESULT: FAIL failures=%0d", failures);
        if (failures != 0)
            $fatal(1, "fault-status test failed");
        $finish;
    end
endmodule

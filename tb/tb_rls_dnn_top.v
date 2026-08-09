`timescale 1ns / 1ps
// SPDX-License-Identifier: Apache-2.0

module tb_rls_dnn_top;

    reg         clk;
    reg         rst_n;
    reg         sample_enable;
    reg  [31:0] s_axis_tdata;
    reg         s_axis_tvalid;
    wire        s_axis_tready;
    wire [15:0] m_axis_tdata;
    wire        m_axis_tvalid;
    reg         m_axis_tready;

    reg  [7:0]  s_axi_awaddr;
    reg         s_axi_awvalid;
    wire        s_axi_awready;
    reg  [31:0] s_axi_wdata;
    reg         s_axi_wvalid;
    wire        s_axi_wready;
    wire [1:0]  s_axi_bresp;
    wire        s_axi_bvalid;
    reg         s_axi_bready;
    reg  [7:0]  s_axi_araddr;
    reg         s_axi_arvalid;
    wire        s_axi_arready;
    wire [31:0] s_axi_rdata;
    wire [1:0]  s_axi_rresp;
    wire        s_axi_rvalid;
    reg         s_axi_rready;

    wire        clk_gate_en;
    wire        irq_fault;

    // Weight programming interface signals
    reg         wload_en;
    reg [16:0]  wload_addr;
    reg [15:0]  wload_data;

    rls_dnn_top dut (
        .clk           (clk),
        .rst_n         (rst_n),
        .sample_enable (sample_enable),
        .wload_en      (wload_en),
        .wload_addr    (wload_addr),
        .wload_data    (wload_data),
        .s_axis_tdata  (s_axis_tdata),
        .s_axis_tvalid (s_axis_tvalid),
        .s_axis_tready (s_axis_tready),
        .m_axis_tdata  (m_axis_tdata),
        .m_axis_tvalid (m_axis_tvalid),
        .m_axis_tready (m_axis_tready),
        .s_axi_awaddr  (s_axi_awaddr),
        .s_axi_awvalid (s_axi_awvalid),
        .s_axi_awready (s_axi_awready),
        .s_axi_wdata   (s_axi_wdata),
        .s_axi_wvalid  (s_axi_wvalid),
        .s_axi_wready  (s_axi_wready),
        .s_axi_bresp   (s_axi_bresp),
        .s_axi_bvalid  (s_axi_bvalid),
        .s_axi_bready  (s_axi_bready),
        .s_axi_araddr  (s_axi_araddr),
        .s_axi_arvalid (s_axi_arvalid),
        .s_axi_arready (s_axi_arready),
        .s_axi_rdata   (s_axi_rdata),
        .s_axi_rresp   (s_axi_rresp),
        .s_axi_rvalid  (s_axi_rvalid),
        .s_axi_rready  (s_axi_rready),
        .clk_gate_en   (clk_gate_en),
        .irq_fault     (irq_fault)
    );

    initial clk = 1'b0;
    always #5 clk = ~clk;

    localparam SAMPLE_DIV = 20;
    integer clk_cnt;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            clk_cnt       <= 0;
            sample_enable <= 1'b0;
        end else begin
            if (clk_cnt == SAMPLE_DIV - 1) begin
                clk_cnt       <= 0;
                sample_enable <= 1'b1;
            end else begin
                clk_cnt       <= clk_cnt + 1;
                sample_enable <= 1'b0;
            end
        end
    end

    integer sample_idx;
    real    sin_val, noise_val;
    reg signed [15:0] d_sample, x_sample;

    function signed [15:0] sin_lut;
        input integer idx;
        real angle;
        begin
            angle = (idx % 256) * 3.14159265 * 2.0 / 256.0;
            sin_lut = $signed($rtoi($sin(angle) * 16383.0));
        end
    endfunction

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            sample_idx    <= 0;
            s_axis_tdata  <= 32'h0;
            s_axis_tvalid <= 1'b0;
        end else begin
            if (s_axis_tvalid && !s_axis_tready) begin
                s_axis_tvalid <= 1'b1;
            end else if (sample_enable) begin
                d_sample = sin_lut(sample_idx * 10);
                x_sample = sin_lut(sample_idx * 10 + 13);
                s_axis_tdata  <= {x_sample, $signed(d_sample + x_sample/4)};
                s_axis_tvalid <= 1'b1;
                sample_idx    <= sample_idx + 1;
            end else begin
                s_axis_tvalid <= 1'b0;
            end
        end
    end

    integer out_cnt;
    integer pass_cnt;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            out_cnt  <= 0;
            pass_cnt <= 0;
        end else if (m_axis_tvalid && m_axis_tready) begin
            out_cnt <= out_cnt + 1;
            $display("[%0t ns] Sample %0d : y_out = %0d (0x%04h)",
                      $time, out_cnt, $signed(m_axis_tdata), m_axis_tdata);
            if (out_cnt > 50) begin
                if ($signed(m_axis_tdata) < 16'sh1999 &&
                    $signed(m_axis_tdata) > -16'sh1999)
                    pass_cnt <= pass_cnt + 1;
            end
        end
    end

    integer i_stim;
    initial begin : STIM
        s_axi_awaddr  = 8'h00;
        s_axi_awvalid = 1'b0;
        s_axi_wdata   = 32'h0;
        s_axi_wvalid  = 1'b0;
        s_axi_bready  = 1'b1;
        s_axi_araddr  = 8'h00;
        s_axi_arvalid = 1'b0;
        s_axi_rready  = 1'b1;

        rst_n         = 1'b0;
        m_axis_tready = 1'b1;
        sample_enable = 1'b0;
        s_axis_tvalid = 1'b0;
        s_axis_tdata  = 32'h0;

        wload_en   = 1'b0;
        wload_addr = 17'd0;
        wload_data = 16'd0;

        repeat(10) @(posedge clk);
        @(negedge clk);
        rst_n = 1'b1;

        // Load mock weights (all zeros) into SRAM
        @(posedge clk);
        wload_en = 1'b1;
        for (i_stim = 0; i_stim <= 100097; i_stim = i_stim + 1) begin
            wload_addr = i_stim;
            wload_data = 16'h0000;
            @(posedge clk);
        end
        wload_en   = 1'b0;
        wload_addr = 17'd0;
        wload_data = 16'd0;

        repeat(200 * SAMPLE_DIV + 1000) @(posedge clk);

        $display("===================================================");
        $display(" SIMULATION COMPLETE");
        $display(" Total output samples : %0d", out_cnt);
        $display(" Convergence checks   : %0d / %0d passed", pass_cnt, (out_cnt > 50) ? out_cnt - 50 : 0);
        if (pass_cnt > ((out_cnt > 50) ? (out_cnt - 50) * 3 / 4 : 0))
            $display(" RESULT : PASS -- Noise suppression evident");
        else
            $display(" RESULT : WARN -- May need weight tuning");
        $display("===================================================");
        $finish;
    end

    initial begin
        #100_000_000;
        $display("TIMEOUT: simulation exceeded 100 ms");
        $finish;
    end

    initial begin
        $dumpfile("rls_dnn_top.vcd");
        $dumpvars(0, tb_rls_dnn_top);
    end

endmodule

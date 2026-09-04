// Technology-specific ASIC binding layer.
// Functional mlp_weight_sram_wrapper.v is intentionally unchanged.
// This adapter is qualification collateral for eight 8192x32 single-port
// macros. It requires the system to keep programming requests quiescent while
// a read-modify-write is in progress; the existing interface has no ready
// signal, so that contract remains a project-level gate.
`timescale 1ns/1ps

module mlp_weight_sram_wrapper (
    input wire clk, input wire rst_n,
    input wire wload_en, input wire [16:0] wload_addr,
    input wire [15:0] wload_data,
    input wire ren, input wire [12:0] raddr,
    output reg [255:0] rdata, output reg rvalid
);
    localparam [1:0] S_IDLE = 2'd0, S_RMW = 2'd1;
    reg [1:0] state;
    reg [12:0] rmw_row;
    reg [3:0] rmw_lane;
    reg [15:0] rmw_data;
    wire [12:0] wrow = wload_addr[16:4];
    wire [3:0]  wlane = wload_addr[3:0];
    wire launch_read = (state == S_IDLE) && !wload_en && ren;
    wire launch_rmw = (state == S_IDLE) && wload_en;
    wire macro_read = launch_read || launch_rmw;
    wire macro_write = (state == S_RMW);
    wire [12:0] macro_addr = (state == S_RMW) ? rmw_row : (launch_rmw ? wrow : raddr);

    wire [31:0] mo0, mo1, mo2, mo3, mo4, mo5, mo6, mo7;
    wire [31:0] mi0 = (state == S_RMW && rmw_lane[3:1] == 3'd0) ? (rmw_lane[0] ? {rmw_data,mo0[15:0]} : {mo0[31:16],rmw_data}) : mo0;
    wire [31:0] mi1 = (state == S_RMW && rmw_lane[3:1] == 3'd1) ? (rmw_lane[0] ? {rmw_data,mo1[15:0]} : {mo1[31:16],rmw_data}) : mo1;
    wire [31:0] mi2 = (state == S_RMW && rmw_lane[3:1] == 3'd2) ? (rmw_lane[0] ? {rmw_data,mo2[15:0]} : {mo2[31:16],rmw_data}) : mo2;
    wire [31:0] mi3 = (state == S_RMW && rmw_lane[3:1] == 3'd3) ? (rmw_lane[0] ? {rmw_data,mo3[15:0]} : {mo3[31:16],rmw_data}) : mo3;
    wire [31:0] mi4 = (state == S_RMW && rmw_lane[3:1] == 3'd4) ? (rmw_lane[0] ? {rmw_data,mo4[15:0]} : {mo4[31:16],rmw_data}) : mo4;
    wire [31:0] mi5 = (state == S_RMW && rmw_lane[3:1] == 3'd5) ? (rmw_lane[0] ? {rmw_data,mo5[15:0]} : {mo5[31:16],rmw_data}) : mo5;
    wire [31:0] mi6 = (state == S_RMW && rmw_lane[3:1] == 3'd6) ? (rmw_lane[0] ? {rmw_data,mo6[15:0]} : {mo6[31:16],rmw_data}) : mo6;
    wire [31:0] mi7 = (state == S_RMW && rmw_lane[3:1] == 3'd7) ? (rmw_lane[0] ? {rmw_data,mo7[15:0]} : {mo7[31:16],rmw_data}) : mo7;

    // Full-word write macros require an explicit lane merge. The adapter
    // therefore performs a read-modify-write for each 16-bit load.
    spram_8192_32 u_sram0(.A(macro_addr),.CEB(~macro_read & ~macro_write),.WEB(~macro_write),.OEB(1'b0),.CSB(1'b0),.I(mi0),.O(mo0));
    spram_8192_32 u_sram1(.A(macro_addr),.CEB(~macro_read & ~macro_write),.WEB(~macro_write),.OEB(1'b0),.CSB(1'b0),.I(mi1),.O(mo1));
    spram_8192_32 u_sram2(.A(macro_addr),.CEB(~macro_read & ~macro_write),.WEB(~macro_write),.OEB(1'b0),.CSB(1'b0),.I(mi2),.O(mo2));
    spram_8192_32 u_sram3(.A(macro_addr),.CEB(~macro_read & ~macro_write),.WEB(~macro_write),.OEB(1'b0),.CSB(1'b0),.I(mi3),.O(mo3));
    spram_8192_32 u_sram4(.A(macro_addr),.CEB(~macro_read & ~macro_write),.WEB(~macro_write),.OEB(1'b0),.CSB(1'b0),.I(mi4),.O(mo4));
    spram_8192_32 u_sram5(.A(macro_addr),.CEB(~macro_read & ~macro_write),.WEB(~macro_write),.OEB(1'b0),.CSB(1'b0),.I(mi5),.O(mo5));
    spram_8192_32 u_sram6(.A(macro_addr),.CEB(~macro_read & ~macro_write),.WEB(~macro_write),.OEB(1'b0),.CSB(1'b0),.I(mi6),.O(mo6));
    spram_8192_32 u_sram7(.A(macro_addr),.CEB(~macro_read & ~macro_write),.WEB(~macro_write),.OEB(1'b0),.CSB(1'b0),.I(mi7),.O(mo7));

    always @* begin
        rdata = {mo7,mo6,mo5,mo4,mo3,mo2,mo1,mo0};
    end

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= S_IDLE; rvalid <= 1'b0;
            rmw_row <= 13'd0; rmw_lane <= 4'd0; rmw_data <= 16'd0;
        end else begin
            rvalid <= launch_read;
            if (launch_rmw) begin
                state <= S_RMW;
                rmw_row <= wrow; rmw_lane <= wlane; rmw_data <= wload_data;
            end else if (state == S_RMW) begin
                state <= S_IDLE;
            end
        end
    end
endmodule

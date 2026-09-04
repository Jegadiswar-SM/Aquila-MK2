// Synthesis/elaboration declaration for the C2S SRAM macro.
// The real Verilog timing model is used for ASIC simulation; Genus sees this
// empty black-box declaration so the 8192x256 memory cannot become flops.
(* black_box *)
module spram_8192_32 (
    input wire [12:0] A, input wire CEB, WEB, OEB, CSB,
    input wire [31:0] I, output wire [31:0] O
);
endmodule


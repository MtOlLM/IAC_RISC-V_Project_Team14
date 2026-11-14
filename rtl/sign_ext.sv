module sign_ext #(
    parameter OUTPUT_WIDTH = 32
) (
    input  logic [            31:7] in,
    input  logic [             1:0] imm_src,
    output logic [OUTPUT_WIDTH-1:0] out
);
  always_comb
    case (imm_src)
      2'b10:   out = {{(OUTPUT_WIDTH - 13) {in[31]}}, in[31], in[7], in[30:25], in[11:8],1'b0};  //B type instruction, append the zero at the end
      2'b01:   out = {{(OUTPUT_WIDTH - 12) {in[31]}}, in[31:25], in[11:7]};  //S type instruction
      2'b00:   out = {{(OUTPUT_WIDTH - 12) {in[31]}}, in[31:20]};  // I type instruction
      default: out = '0;
    endcase

endmodule

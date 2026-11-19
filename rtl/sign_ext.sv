module sign_ext #(
    parameter OUTPUT_WIDTH = 32
) (
    input  logic [            31:7] in,
    input  logic [             2:0] imm_src,
    output logic [OUTPUT_WIDTH-1:0] out
);
  typedef enum logic [2:0] {I_TYPE, S_TYPE, B_TYPE, U_TYPE, J_TYPE} instr_type;

  always_comb
    case (imm_src)
      J_TYPE:   out = {{(OUTPUT_WIDTH - 21){in[31]}}, in[19:12], in[20], in[30:25], in[24:21], 1'b0};//append the zero at the end
      U_TYPE:   out = {in[31:12],{(OUTPUT_WIDTH - 20) {1'b0}}};
      B_TYPE:   out = {{(OUTPUT_WIDTH - 13) {in[31]}}, in[31], in[7], in[30:25], in[11:8],1'b0};//append the zero at the end
      S_TYPE:   out = {{(OUTPUT_WIDTH - 12) {in[31]}}, in[31:25], in[11:7]};
      I_TYPE:   out = {{(OUTPUT_WIDTH - 12) {in[31]}}, in[31:20]};
      default: out = '0;
    endcase

endmodule

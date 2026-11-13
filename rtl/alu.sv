module alu #(
    parameter DATA_WIDTH = 32
) (
    input  logic [DATA_WIDTH-1:0] ALUOp1,
    input  logic [DATA_WIDTH-1:0] ALUOp2,
    input  logic [           2:0] ALUctrl,
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic                  eq
);

  always_comb
    case (ALUctrl)
      3'b000:  ALUout = ALUOp1 + ALUOp2;
      3'b001:  ALUout = ALUOp1 - ALUOp2;
      3'b010:  ALUout = ALUOp1 & ALUOp2;
      3'b101:  ALUout = {{(DATA_WIDTH - 1) {1'b0}}, (ALUOp1 < ALUOp2)};
      3'b011:  ALUout = ALUOp1 | ALUOp2;
      default: ALUout = {(DATA_WIDTH) {1'b0}};
    endcase

  assign eq = (ALUOp1 == ALUOp2);
endmodule

module top #(
    DATA_WIDTH = 32
) (
    input  logic                    clk,
    input  logic                    rst,
    output logic [DATA_WIDTH-1 : 0] a0
);
  logic [DATA_WIDTH-1 : 0] pc;
  logic [DATA_WIDTH-1 : 0] instr;  //intruction
  logic [DATA_WIDTH-1 : 0] imm_op;  //immediate oprand
  logic [DATA_WIDTH-1 : 0] ALU_out;
  logic [DATA_WIDTH-1 : 0] src_a, src_b, rd2_op;  //rd2_op is the oprand output from register file RD2 port
  logic [2 : 0] ALU_control;
  logic [1 : 0] imm_src;
  logic reg_write, ALU_src, pc_src;  //control signals
  logic eq;  //ALU if equal output

  ROM instr_mem (
      .addr(pc),
      .data(instr)
  );

  control_unit control_unit (
      .eq(eq),
      .opcode(instr[6:0]),
      .funct3(instr[14:12]),
      .funct7_5(instr[30]),
      .reg_write(reg_write),
      .pc_src(pc_src),
      .imm_src(imm_src),
      .ALU_control(ALU_control),
      .ALU_src(ALU_src)
  );

  sign_ext sign_ext (
      .imm_src(imm_src),
      .in(instr[31:7]),
      .out(imm_op)
  );

  regfile regfile (
      .AD1(instr[19:15]),
      .AD2(instr[24:20]),
      .AD3(instr[11:7]),
      .clk(clk),
      .WE3(reg_write),
      .WD3(ALU_out),
      .RD1(src_a),
      .RD2(rd2_op),
      .a0 (a0)
  );

  mux src_b_mux (
      .in0(rd2_op),
      .in1(imm_op),
      .sel(ALU_src),
      .out(src_b)
  );

  alu ALU (
      .ALUOp1(src_a),
      .ALUOp2(src_b),
      .ALUctrl(ALU_control),
      .ALUout(ALU_out),
      .eq(eq)
  );

endmodule

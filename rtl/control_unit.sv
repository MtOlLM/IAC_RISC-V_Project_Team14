module control_unit (
    input  logic         eq,
    input  logic [  6:0] opcode,
    input  logic [14:12] funct3,
    input  logic         funct7_5,
    output logic         reg_write,
    output logic         pc_src,
    output logic [  1:0] imm_src,
    output logic [  2:0] ALU_control,
    output logic         ALU_src
);
  logic       branch;
  logic [1:0] ALU_op;

  main_decoder main_decoder (
      .ALU_op   (ALU_op),
      .ALU_src  (ALU_src),
      .branch   (branch),
      .imm_src  (imm_src),
      .opcode   (opcode),
      .reg_write(reg_write)
  );

  ALU_decoder ALU_decoder (
      .ALU_control(ALU_control),
      .ALU_op     (ALU_op),
      .funct3     (funct3),
      .funct7_5   (funct7_5),
      .opcode     (opcode)
  );

  assign pc_src = ~eq & branch;

endmodule

module main_decoder (
    input  logic [6:0] opcode,
    output logic       reg_write,
    output logic [1:0] imm_src,
    output logic       ALU_src,
    output logic       branch,
    output logic [1:0] ALU_op
);
  localparam logic [6:0] OPTYPE_R   = 7'b0110011;
  localparam logic [6:0] OPTYPE_I   = 7'b0010011;
  localparam logic [6:0] OPTYPE_S   = 7'b0100011;
  localparam logic [6:0] OPTYPE_B   = 7'b1100011;
  localparam logic [6:0] OPTYPE_I_L = 7'b0000011;  //load instructions

  always_comb begin
    reg_write = 1'b0;
    ALU_op = 2'b00;
    imm_src = 2'b00;
    ALU_src = 1'b0;
    branch = 1'b0;

    case (opcode)
      OPTYPE_R: begin
        reg_write = 1'b1;
        ALU_op = 2'b10;
      end
      OPTYPE_I: begin
        reg_write = 1'b1;
        ALU_op = 2'b10;
        ALU_src = 1'b1;
      end
      OPTYPE_S: begin
        imm_src = 2'b01;
        ALU_src = 1'b1;
      end
      OPTYPE_B: begin
        branch  = 1'b1;
        imm_src = 2'b10;
        ALU_op  = 2'b01;
      end
      OPTYPE_I_L: begin
        reg_write = 1'b1;
        ALU_src   = 1'b1;
      end
      default: ;
    endcase
  end
endmodule

module ALU_decoder (
    input  logic [  1:0] ALU_op,
    input  logic [  6:0] opcode,
    input  logic [14:12] funct3,
    input  logic         funct7_5,
    output logic [  2:0] ALU_control
);
  always_comb begin
    if (!ALU_op[1]) ALU_control = {1'b0, ALU_op};
    else
      case (funct3)
        3'b000:  ALU_control = {2'b00, opcode[5] & funct7_5};
        3'b010:  ALU_control = 3'b101;
        3'b110:  ALU_control = 3'b011;
        3'b111:  ALU_control = 3'b010;
        default: ALU_control = 3'b000;
      endcase
  end
endmodule

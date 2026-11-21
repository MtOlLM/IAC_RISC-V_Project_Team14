module top #(
    parameter DATA_WIDTH = 32
) (
    input  logic                    clk,
    input  logic                    rst,
    output logic [DATA_WIDTH-1 : 0] a0
);
    //intruction
    logic [DATA_WIDTH-1 : 0] instr;

    //PC
    logic [DATA_WIDTH-1 : 0] pc, inc_pc;
    
    //Data
    logic [DATA_WIDTH-1 : 0] imm_op;  //immediate oprand
    logic [DATA_WIDTH-1 : 0] ALU_out, mem_out, result;
    logic [DATA_WIDTH-1 : 0] alu_op1, alu_op2, rs1, rs2;

    //control signals
    logic [2:0] branch_ctrl;
    logic       reg_write;
    logic [1:0] pc_src;
    logic [2:0] imm_src;
    logic [4:0] ALU_control;
    logic [2:1] ALU_src;
    logic [3:0] mem_write;
    logic [1:0] result_src;


    ROM instr_mem (
        .addr(pc),
        .data(instr)
    );

    control_unit control_unit (
        .branch_ctrl(branch_ctrl),
        .opcode     (instr[6:0]),
        .funct3     (instr[14:12]),
        .funct7_5   (instr[30]),
        .funct7_0   (instr[25]),
        .reg_write  (reg_write),
        .pc_src     (pc_src),
        .imm_src    (imm_src),
        .ALU_control(ALU_control),
        .ALU_src    (ALU_src),
        .mem_write  (mem_write),
        .result_src (result_src)
    );

    sign_ext sign_ext (
        .imm_src(imm_src),
        .in     (instr[31:7]),
        .out    (imm_op)
    );

    regfile regfile (
        .AD1(instr[19:15]),
        .AD2(instr[24:20]),
        .AD3(instr[11:7]),
        .clk(clk),
        .WE3(reg_write),
        .WD3(result),
        .RD1(rs1),
        .RD2(rs2),
        .a0 (a0)
    );

    mux ALU_op1_mux (
        .in0(rs1),
        .in1(pc),
        .sel(ALU_src[1]),
        .out(alu_op1)
    );

    mux ALU_op2_mux (
        .in0(rs2),
        .in1(imm_op),
        .sel(ALU_src[2]),
        .out(alu_op2)
    );

    alu ALU (
        .ALUOp1     (alu_op1),
        .ALUOp2     (alu_op2),
        .ALUctrl    (ALU_control),
        .ALUout     (ALU_out),
        .branch_ctrl(branch_ctrl)
    );

    program_counter program_counter (
        .clk   (clk),
        .rst   (rst),
        .rs1   (rs1),
        .pc_src(pc_src),
        .imm_op(imm_op),
        .pc    (pc),
        .inc_pc(inc_pc)
    );

    mcu MCU (
        .clk     (clk),
        .w_en    (mem_write),
        .funct3  (instr[14:12]),
        .data_in (rd2_op),
        .addr    (ALU_out),
        .data_out(mem_out)
    );

    mux4 result_mux (
        .in0(ALU_out),
        .in1(mem_out),
        .in2(imm_op),
        .in3(inc_pc),
        .sel(result_src),
        .out(result)
    );


endmodule

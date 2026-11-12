module top #(
    DATA_WIDTH = 32
) (
    input   logic clk,
    input   logic rst,
    output  logic [DATA_WIDTH-1:0] a0    
);
    logic [DATA_WIDTH-1 : 0] pc;
    logic [DATA_WIDTH-1 : 0] instr; //intruction
    logic [DATA_WIDTH-1 : 0] imm_op; //immediate oprand
    logic reg_write, ALU_control, ALU_src, imm_src, pc_src; //control signals
    logic eq; //ALU if equal output

    ROM instr_mem(
        .addr(pc),
        .data(instr)
    );

    control_unit control_unit(
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

    sign_ext sign_ext(
        .imm_src(imm_src),
        .in(instr[31:7]),
        .out(imm_op)
    );


endmodule

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
    logic [3:0] branch_ctrl;
    logic       reg_write;
    logic       branch, jump, jalr;     //instruction type from the control unit
    logic       pc_src;                 //1 = take pc_target
    logic [DATA_WIDTH-1 : 0] pc_target; //branch/jump target address
    logic [2:0] imm_src;
    logic [3:0] ALU_control;
    logic [2:1] ALU_src;
    logic [3:0] mem_write;
    logic [1:0] result_src;


    ROM instr_mem (
        .addr(pc),
        .data(instr)
    );

    control_unit control_unit (
        .opcode     (instr[6:0]),
        .funct3     (instr[14:12]),
        .funct7_5   (instr[30]),
        .reg_write  (reg_write),
        .branch     (branch),
        .jump       (jump),
        .jalr       (jalr),
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

    branch_unit branch_unit (
        .branch     (branch),
        .jump       (jump),
        .funct3     (instr[14:12]),
        .branch_ctrl(branch_ctrl),
        .pc_src     (pc_src)
    );

    // choose between pc and rs1 for jalr instruction, then add the immediate offset to get the target address 
    assign pc_target = ((jalr ? rs1 : pc) + imm_op) & ~32'd1;

    program_counter program_counter (
        .clk      (clk),
        .rst      (rst),
        .en       (1'b1),        // for stalling
        .pc_src   (pc_src),
        .pc_target(pc_target),
        .pc       (pc),
        .inc_pc   (inc_pc)
    );

    mcu MCU (
        .clk     (clk),
        .w_en    (mem_write),
        .funct3  (instr[14:12]),
        .data_in (rs2),
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

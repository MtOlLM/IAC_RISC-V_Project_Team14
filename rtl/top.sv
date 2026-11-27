module top #(
    parameter DATA_WIDTH = 32
) (
    input  logic                    clk,
    input  logic                    rst,
    output logic [DATA_WIDTH-1 : 0] a0
);
    // F, D, E, M and W denote fetch, decode, execute, memory and writeback.
    // Combinational connections between stages keep the datapath single-cycle.

    // Fetch
    logic [DATA_WIDTH-1:0] pcF, pc_plus4F, instrF;

    // Decode
    logic [DATA_WIDTH-1:0] instrD, pcD, pc_plus4D, rd1D, rd2D, immD;
    logic                 reg_writeD, branchD, jumpD, jalrD;
    logic [2:0]           imm_srcD;
    logic [3:0]           ALU_controlD, mem_writeD;
    logic [2:1]           ALU_srcD;
    logic [1:0]           result_srcD;

    // Execute
    logic [DATA_WIDTH-1:0] rd1E, rd2E, pcE, pc_plus4E, immE;
    logic [DATA_WIDTH-1:0] alu_op1E, alu_op2E, alu_outE, pc_targetE;
    logic [4:0]           rdE;
    logic [2:0]           funct3E;
    logic                 reg_writeE, branchE, jumpE, jalrE, pc_srcE;
    logic [3:0]           ALU_controlE, branch_ctrlE, mem_writeE;
    logic [2:1]           ALU_srcE;
    logic [1:0]           result_srcE;

    // Memory
    logic [DATA_WIDTH-1:0] alu_outM, write_dataM, immM, pc_plus4M, mem_outM;
    logic [4:0]           rdM;
    logic [2:0]           funct3M;
    logic                 reg_writeM;
    logic [3:0]           mem_writeM;
    logic [1:0]           result_srcM;

    // Writeback
    logic [DATA_WIDTH-1:0] alu_outW, mem_outW, immW, pc_plus4W, resultW;
    logic [4:0]           rdW;
    logic                 reg_writeW;
    logic [1:0]           result_srcW;

    // Fetch
    program_counter program_counter (
        .clk      (clk),
        .rst      (rst),
        .en       (1'b1),
        .pc_src   (pc_srcE),
        .pc_target(pc_targetE),
        .pc       (pcF),
        .inc_pc   (pc_plus4F)
    );

    ROM instr_mem (
        .addr(pcF),
        .data(instrF)
    );

    assign {instrD, pcD, pc_plus4D} = {instrF, pcF, pc_plus4F};

    // Decode
    control_unit control_unit (
        .opcode     (instrD[6:0]),
        .funct3     (instrD[14:12]),
        .funct7_5   (instrD[30]),
        .reg_write  (reg_writeD),
        .branch     (branchD),
        .jump       (jumpD),
        .jalr       (jalrD),
        .imm_src    (imm_srcD),
        .ALU_control(ALU_controlD),
        .ALU_src    (ALU_srcD),
        .mem_write  (mem_writeD),
        .result_src (result_srcD)
    );

    sign_ext sign_ext (
        .imm_src(imm_srcD),
        .in     (instrD[31:7]),
        .out    (immD)
    );

    regfile regfile (
        .AD1(instrD[19:15]),
        .AD2(instrD[24:20]),
        .AD3(rdW),
        .clk(clk),
        .WE3(reg_writeW),
        .WD3(resultW),
        .RD1(rd1D),
        .RD2(rd2D),
        .a0 (a0)
    );

    assign {rd1E, rd2E, pcE, pc_plus4E, immE, rdE, funct3E,
            reg_writeE, branchE, jumpE, jalrE,
            result_srcE, mem_writeE, ALU_controlE, ALU_srcE}
         = {rd1D, rd2D, pcD, pc_plus4D, immD, instrD[11:7], instrD[14:12],
            reg_writeD, branchD, jumpD, jalrD,
            result_srcD, mem_writeD, ALU_controlD, ALU_srcD};

    // Execute
    mux ALU_op1_mux (
        .in0(rd1E),
        .in1(pcE),
        .sel(ALU_srcE[1]),
        .out(alu_op1E)
    );

    mux ALU_op2_mux (
        .in0(rd2E),
        .in1(immE),
        .sel(ALU_srcE[2]),
        .out(alu_op2E)
    );

    alu ALU (
        .ALUOp1     (alu_op1E),
        .ALUOp2     (alu_op2E),
        .ALUctrl    (ALU_controlE),
        .ALUout     (alu_outE),
        .branch_ctrl(branch_ctrlE)
    );

    branch_unit branch_unit (
        .branch     (branchE),
        .jump       (jumpE),
        .funct3     (funct3E),
        .branch_ctrl(branch_ctrlE),
        .pc_src     (pc_srcE)
    );

    // JALR uses rs1 as its base. Other targets use the instruction PC.
    assign pc_targetE = ((jalrE ? rd1E : pcE) + immE) & ~32'd1;

    assign {alu_outM, write_dataM, immM, pc_plus4M,
            rdM, funct3M, reg_writeM, result_srcM, mem_writeM}
         = {alu_outE, rd2E, immE, pc_plus4E,
            rdE, funct3E, reg_writeE, result_srcE, mem_writeE};

    // Memory
    mcu MCU (
        .clk     (clk),
        .w_en    (mem_writeM),
        .funct3  (funct3M),
        .data_in (write_dataM),
        .addr    (alu_outM),
        .data_out(mem_outM)
    );

    assign {alu_outW, mem_outW, immW, pc_plus4W, rdW, reg_writeW, result_srcW}
         = {alu_outM, mem_outM, immM, pc_plus4M, rdM, reg_writeM, result_srcM};

    // Writeback
    mux4 result_mux (
        .in0(alu_outW),
        .in1(mem_outW),
        .in2(immW),
        .in3(pc_plus4W),
        .sel(result_srcW),
        .out(resultW)
    );
endmodule

module top #(
    parameter DATA_WIDTH = 32
) (
    input  logic                    clk,
    input  logic                    rst,
    output logic [DATA_WIDTH-1 : 0] a0
);
    // F, D, E, M and W denote fetch, decode, execute, memory and writeback.
    // A cleared valid bit marks a bubble.

    // Fetch
    logic [DATA_WIDTH-1:0] pcF, pc_plus4F, instrF;

    // Decode
    logic [DATA_WIDTH-1:0] instrD, pcD, pc_plus4D, rd1D, rd2D, immD;
    logic                 validD, reg_writeD, branchD, jumpD, jalrD;
    logic [2:0]           imm_srcD;
    logic [3:0]           ALU_controlD, mem_writeD;
    logic [2:1]           ALU_srcD;
    logic [1:0]           result_srcD;

    // Execute
    logic [DATA_WIDTH-1:0] rd1E, rd2E, pcE, pc_plus4E, immE;
    logic [DATA_WIDTH-1:0] alu_op1E, alu_op2E, alu_outE, pc_targetE;
    logic [4:0]           rdE;
    logic [2:0]           funct3E;
    logic                 validE, reg_writeE, branchE, jumpE, jalrE, pc_srcE;
    logic [3:0]           ALU_controlE, branch_ctrlE, mem_writeE;
    logic [2:1]           ALU_srcE;
    logic [1:0]           result_srcE;

    // Memory
    logic [DATA_WIDTH-1:0] alu_outM, write_dataM, immM, pc_plus4M, mem_outM;
    logic [4:0]           rdM;
    logic [2:0]           funct3M;
    logic                 validM, reg_writeM;
    logic [3:0]           mem_writeM, store_enM;
    logic [1:0]           result_srcM;

    // Writeback
    logic [DATA_WIDTH-1:0] alu_outW, mem_outW, immW, pc_plus4W, resultW;
    logic [4:0]           rdW;
    logic                 validW, reg_writeW;
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

    // Fetch/decode registers
    pipe_reg #(.WIDTH(DATA_WIDTH)) fd_instr_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(instrF), .q(instrD)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) fd_pc_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(pcF), .q(pcD)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) fd_pc_plus4_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(pc_plus4F), .q(pc_plus4D)
    );
    pipe_reg #(.WIDTH(1)) fd_valid_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(1'b1), .q(validD)
    );

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
        .WE3(reg_writeW & validW),
        .WD3(resultW),
        .RD1(rd1D),
        .RD2(rd2D),
        .a0 (a0)
    );

    // Decode/execute registers
    pipe_reg #(.WIDTH(DATA_WIDTH)) de_rd1_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(rd1D), .q(rd1E)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) de_rd2_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(rd2D), .q(rd2E)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) de_pc_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(pcD), .q(pcE)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) de_pc_plus4_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(pc_plus4D), .q(pc_plus4E)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) de_imm_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(immD), .q(immE)
    );
    pipe_reg #(.WIDTH(5)) de_rd_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(instrD[11:7]), .q(rdE)
    );
    pipe_reg #(.WIDTH(3)) de_funct3_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(instrD[14:12]), .q(funct3E)
    );
    pipe_reg #(.WIDTH(1)) de_reg_write_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(reg_writeD), .q(reg_writeE)
    );
    pipe_reg #(.WIDTH(1)) de_branch_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(branchD), .q(branchE)
    );
    pipe_reg #(.WIDTH(1)) de_jump_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(jumpD), .q(jumpE)
    );
    pipe_reg #(.WIDTH(1)) de_jalr_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(jalrD), .q(jalrE)
    );
    pipe_reg #(.WIDTH(2)) de_result_src_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(result_srcD), .q(result_srcE)
    );
    pipe_reg #(.WIDTH(4)) de_mem_write_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(mem_writeD), .q(mem_writeE)
    );
    pipe_reg #(.WIDTH(4)) de_alu_control_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(ALU_controlD), .q(ALU_controlE)
    );
    pipe_reg #(.WIDTH(2)) de_alu_src_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(ALU_srcD), .q(ALU_srcE)
    );
    pipe_reg #(.WIDTH(1)) de_valid_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(validD), .q(validE)
    );

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
        .branch     (branchE & validE),
        .jump       (jumpE & validE),
        .funct3     (funct3E),
        .branch_ctrl(branch_ctrlE),
        .pc_src     (pc_srcE)
    );

    // JALR uses rs1 as its base. Other targets use the instruction PC.
    assign pc_targetE = ((jalrE ? rd1E : pcE) + immE) & ~32'd1;

    // Execute/memory registers
    pipe_reg #(.WIDTH(DATA_WIDTH)) em_alu_out_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(alu_outE), .q(alu_outM)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) em_write_data_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(rd2E), .q(write_dataM)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) em_imm_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(immE), .q(immM)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) em_pc_plus4_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(pc_plus4E), .q(pc_plus4M)
    );
    pipe_reg #(.WIDTH(5)) em_rd_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(rdE), .q(rdM)
    );
    pipe_reg #(.WIDTH(3)) em_funct3_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(funct3E), .q(funct3M)
    );
    pipe_reg #(.WIDTH(1)) em_reg_write_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(reg_writeE), .q(reg_writeM)
    );
    pipe_reg #(.WIDTH(2)) em_result_src_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(result_srcE), .q(result_srcM)
    );
    pipe_reg #(.WIDTH(4)) em_mem_write_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(mem_writeE), .q(mem_writeM)
    );
    pipe_reg #(.WIDTH(1)) em_valid_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(validE), .q(validM)
    );

    // Memory
    assign store_enM = validM ? mem_writeM : 4'b0000;

    mcu MCU (
        .clk     (clk),
        .w_en    (store_enM),
        .funct3  (funct3M),
        .data_in (write_dataM),
        .addr    (alu_outM),
        .data_out(mem_outM)
    );

    // Memory/writeback registers
    pipe_reg #(.WIDTH(DATA_WIDTH)) mw_alu_out_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(alu_outM), .q(alu_outW)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) mw_mem_out_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(mem_outM), .q(mem_outW)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) mw_imm_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(immM), .q(immW)
    );
    pipe_reg #(.WIDTH(DATA_WIDTH)) mw_pc_plus4_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(pc_plus4M), .q(pc_plus4W)
    );
    pipe_reg #(.WIDTH(5)) mw_rd_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(rdM), .q(rdW)
    );
    pipe_reg #(.WIDTH(1)) mw_reg_write_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(reg_writeM), .q(reg_writeW)
    );
    pipe_reg #(.WIDTH(2)) mw_result_src_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(result_srcM), .q(result_srcW)
    );
    pipe_reg #(.WIDTH(1)) mw_valid_reg (
        .clk(clk), .rst(rst), .en(1'b1), .clr(1'b0),
        .d(validM), .q(validW)
    );

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

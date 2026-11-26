module decode_execute_reg (
    input  logic        clk,
    input  logic        rst,
    input  logic        clr,         // 1 = flush: bubble
    // data
    input  logic [31:0] rd1D, rd2D, pcD, pc_plus4D, immD,
    input  logic [ 4:0] rs1D, rs2D, rdD,
    input  logic [ 2:0] funct3D,
    // control
    input  logic        reg_writeD, branchD, jumpD, jalrD,
    input  logic [ 1:0] result_srcD,
    input  logic [ 3:0] mem_writeD,
    input  logic [ 3:0] ALU_controlD,
    input  logic [ 2:1] ALU_srcD,
    input  logic        validD,

    output logic [31:0] rd1E, rd2E, pcE, pc_plus4E, immE,
    output logic [ 4:0] rs1E, rs2E, rdE,
    output logic [ 2:0] funct3E,
    output logic        reg_writeE, branchE, jumpE, jalrE,
    output logic [ 1:0] result_srcE,
    output logic [ 3:0] mem_writeE,
    output logic [ 3:0] ALU_controlE,
    output logic [ 2:1] ALU_srcE,
    output logic        validE
);
    always_ff @(posedge clk)
        if (rst || clr) begin
            rd1E <= '0; rd2E <= '0; pcE <= '0; pc_plus4E <= '0; immE <= '0;
            rs1E <= '0; rs2E <= '0; rdE <= '0; funct3E <= '0;
            reg_writeE <= 1'b0; branchE <= 1'b0; jumpE <= 1'b0; jalrE <= 1'b0;
            result_srcE <= '0; mem_writeE <= '0; ALU_controlE <= '0; ALU_srcE <= '0;
            validE <= 1'b0;
        end else begin
            rd1E <= rd1D; rd2E <= rd2D; pcE <= pcD; pc_plus4E <= pc_plus4D; immE <= immD;
            rs1E <= rs1D; rs2E <= rs2D; rdE <= rdD; funct3E <= funct3D;
            reg_writeE <= reg_writeD; branchE <= branchD; jumpE <= jumpD; jalrE <= jalrD;
            result_srcE <= result_srcD; mem_writeE <= mem_writeD;
            ALU_controlE <= ALU_controlD; ALU_srcE <= ALU_srcD;
            validE <= validD;
        end
endmodule

module execute_memory_reg (
    input  logic        clk,
    input  logic        rst,
    input  logic [31:0] alu_outE, write_dataE, immE, pc_plus4E,
    input  logic [ 4:0] rdE,
    input  logic [ 2:0] funct3E,
    input  logic        reg_writeE,
    input  logic [ 1:0] result_srcE,
    input  logic [ 3:0] mem_writeE,
    input  logic        validE,

    output logic [31:0] alu_outM, write_dataM, immM, pc_plus4M,
    output logic [ 4:0] rdM,
    output logic [ 2:0] funct3M,
    output logic        reg_writeM,
    output logic [ 1:0] result_srcM,
    output logic [ 3:0] mem_writeM,
    output logic        validM
);
    always_ff @(posedge clk)
        if (rst) begin
            alu_outM <= '0; write_dataM <= '0; immM <= '0; pc_plus4M <= '0;
            rdM <= '0; funct3M <= '0; reg_writeM <= 1'b0; result_srcM <= '0;
            mem_writeM <= '0; validM <= 1'b0;
        end else begin
            alu_outM <= alu_outE;
            write_dataM <= write_dataE;
            immM <= immE;
            pc_plus4M <= pc_plus4E;
            rdM <= rdE;
            funct3M <= funct3E;
            reg_writeM <= reg_writeE;
            result_srcM <= result_srcE;
            mem_writeM <= mem_writeE;
            validM <= validE;
        end
endmodule

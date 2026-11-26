module memory_writeback_reg (
    input  logic        clk,
    input  logic        rst,
    input  logic [31:0] alu_outM, mem_outM, immM, pc_plus4M,
    input  logic [ 4:0] rdM,
    input  logic        reg_writeM,
    input  logic [ 1:0] result_srcM,
    input  logic        validM,

    output logic [31:0] alu_outW, mem_outW, immW, pc_plus4W,
    output logic [ 4:0] rdW,
    output logic        reg_writeW,
    output logic [ 1:0] result_srcW,
    output logic        validW
);
    always_ff @(posedge clk)
        if (rst) begin
            alu_outW <= '0; mem_outW <= '0; immW <= '0; pc_plus4W <= '0;
            rdW <= '0; reg_writeW <= 1'b0; result_srcW <= '0; validW <= 1'b0;
        end else begin
            alu_outW <= alu_outM;
            mem_outW <= mem_outM;
            immW <= immM;
            pc_plus4W <= pc_plus4M;
            rdW <= rdM;
            reg_writeW <= reg_writeM;
            result_srcW <= result_srcM;
            validW <= validM;
        end
endmodule

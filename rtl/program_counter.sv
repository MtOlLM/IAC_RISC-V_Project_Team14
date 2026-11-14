module program_counter #(
    parameter logic [31:0] RESET_PC = 32'h0000_0000
) (
    input  logic clk,
    input  logic rst,
    input  logic pc_src,
    input  logic [31:0] imm_op,
    output logic [31:0] pc
);
    logic [31:0] inc_pc;
    logic [31:0] branch_pc;
    logic [31:0] next_pc;

    assign inc_pc = pc + 32'd4;
    assign branch_pc = pc + imm_op;
    assign next_pc = pc_src ? branch_pc : inc_pc;

    always_ff @(posedge clk) begin
        if (rst)
            pc <= RESET_PC;
        else
            pc <= next_pc;
    end
endmodule

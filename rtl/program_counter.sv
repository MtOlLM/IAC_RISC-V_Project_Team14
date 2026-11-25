module program_counter #(
    parameter logic [31:0] RESET_PC = 32'hBFC0_0000
) (
    input  logic        clk,
    input  logic        rst,
    input  logic        en,         // 0 = stall (hold pc)
    input  logic        pc_src,     // 1 = jump to pc_target
    input  logic [31:0] pc_target,  // branch/jump target, computed outside the PC
    output logic [31:0] pc,
    output logic [31:0] inc_pc
);
    assign inc_pc = pc + 32'd4; // instruction width is 4 bytes

    always_ff @(posedge clk) begin
        if (rst)     pc <= RESET_PC;
        else if (en) pc <= pc_src ? pc_target : inc_pc;
    end
endmodule

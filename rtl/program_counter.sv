module program_counter #(
    parameter logic [31:0] reset_pc = 32'h00000000
) (
    input  logic clk,
    input  logic rst,
    input  logic pcsrc,
    input  logic [31:0] immop,
    output logic [31:0] pc
);
    logic [31:0] inc_pc;
    logic [31:0] branch_pc;
    logic [31:0] next_pc;

    assign inc_pc = pc + 32'd4;
    assign branch_pc = pc + immop;
    assign next_pc = pcsrc ? branch_pc : inc_pc;

    always_ff @(posedge clk) begin
        if (rst)
            pc <= reset_pc;
        else
            pc <= next_pc;
    end
endmodule
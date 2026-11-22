module program_counter #(
    parameter logic [31:0] RESET_PC = 32'hBFC0_0000
) (
    input  logic        clk,
    input  logic        rst,
    input  logic [31:0] rs1,
    input  logic [ 1:0] pc_src,
    input  logic [31:0] imm_op,
    output logic [31:0] pc,
    output logic [31:0] inc_pc
);
    logic [31:0] relative_pc;  //branch and jal
    logic [31:0] absolute_pc;  //jalr
    logic [31:0] next_pc;

    always_comb begin
        inc_pc = pc + 32'd4;
        relative_pc = pc + imm_op;
        absolute_pc = (rs1 + imm_op) & 32'hFFFF_FFFE;
        case (pc_src)
            2'b00:   next_pc = inc_pc;
            2'b01:   next_pc = relative_pc;
            2'b10:   next_pc = absolute_pc;
            default: next_pc = inc_pc;
        endcase
    end

    always_ff @(posedge clk) begin
        if (rst) pc <= RESET_PC;
        else pc <= next_pc;
    end
endmodule

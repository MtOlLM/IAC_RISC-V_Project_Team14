module alu #(
    parameter DATA_WIDTH = 32
) (
    input  logic [DATA_WIDTH-1:0] ALUOp1,
    input  logic [DATA_WIDTH-1:0] ALUOp2,
    input  logic [           3:0] ALUctrl,
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic [           3:0] branch_ctrl
);
    // Encoding = {funct7[5], funct3}, so decode is just a concatenation
    typedef enum logic [3:0] {
        ADD  = 4'b0_000,
        SLL  = 4'b0_001,
        SLT  = 4'b0_010,
        SLTU = 4'b0_011,
        XOR  = 4'b0_100,
        SRL  = 4'b0_101,
        OR   = 4'b0_110,
        AND  = 4'b0_111,
        SUB  = 4'b1_000,
        SRA  = 4'b1_101
    } alu_opc;

    always_comb
        case (ALUctrl)
            ADD:     ALUout = ALUOp1 + ALUOp2;
            SLL:     ALUout = ALUOp1 << (ALUOp2[4:0]);
            SLT:     ALUout = {{(DATA_WIDTH - 1) {1'b0}}, ($signed(ALUOp1) < $signed(ALUOp2))};
            SLTU:    ALUout = {{(DATA_WIDTH - 1) {1'b0}}, (ALUOp1 < ALUOp2)};
            XOR:     ALUout = ALUOp1 ^ ALUOp2;
            SRL:     ALUout = ALUOp1 >> (ALUOp2[4:0]);
            OR:      ALUout = ALUOp1 | ALUOp2;
            AND:     ALUout = ALUOp1 & ALUOp2;
            SUB:     ALUout = ALUOp1 - ALUOp2;
            SRA:     ALUout = ALUOp1 >>> (ALUOp2[4:0]);
            default: ALUout = {(DATA_WIDTH) {1'b0}};
        endcase

    assign branch_ctrl = {
        ALUOp1 == ALUOp2,
        1'b0, //a useless bit just to make the decode easier
        $signed(ALUOp1) < $signed(ALUOp2),
        ALUOp1 < ALUOp2
    };
endmodule

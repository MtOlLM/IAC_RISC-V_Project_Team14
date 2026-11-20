module alu #(
    parameter DATA_WIDTH = 32
) (
    input  logic [DATA_WIDTH-1:0] ALUOp1,
    input  logic [DATA_WIDTH-1:0] ALUOp2,
    input  logic [           4:0] ALUctrl,
    output logic [DATA_WIDTH-1:0] ALUout,
    output logic [           2:0] branch_ctrl
);
    logic [DATA_WIDTH-1:0] i_out, m_out;

    mux alu_out_mux (
        .in0(i_out),
        .in1(m_out),
        .sel(ALUctrl[4]),
        .out(ALUout)
    );

    alu_i #(
        .DATA_WIDTH(DATA_WIDTH)
    ) alu_i (
        .ALUOp1     (ALUOp1),
        .ALUOp2     (ALUOp2),
        .ALUctrl    (ALUctrl[3:0]),
        .i_out      (i_out),
        .branch_ctrl(branch_ctrl)
    );

    alu_m #(
        .DATA_WIDTH(DATA_WIDTH)
    ) alu_m (
        .ALUOp1 (ALUOp1),
        .ALUOp2 (ALUOp2),
        .ALUctrl(ALUctrl[2:0]),
        .m_out  (m_out)
    );

endmodule

module alu_i #(
    parameter DATA_WIDTH = 32
) (
    input  logic [DATA_WIDTH-1:0] ALUOp1,
    input  logic [DATA_WIDTH-1:0] ALUOp2,
    input  logic [           3:0] ALUctrl,
    output logic [DATA_WIDTH-1:0] i_out,
    output logic [           2:0] branch_ctrl
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
            ADD:     i_out = ALUOp1 + ALUOp2;
            SLL:     i_out = ALUOp1 << (ALUOp2[4:0]);
            SLT:     i_out = {{(DATA_WIDTH - 1) {1'b0}}, ($signed(ALUOp1) < $signed(ALUOp2))};
            SLTU:    i_out = {{(DATA_WIDTH - 1) {1'b0}}, (ALUOp1 < ALUOp2)};
            XOR:     i_out = ALUOp1 ^ ALUOp2;
            SRL:     i_out = ALUOp1 >> (ALUOp2[4:0]);
            OR:      i_out = ALUOp1 | ALUOp2;
            AND:     i_out = ALUOp1 & ALUOp2;
            SUB:     i_out = ALUOp1 - ALUOp2;
            SRA:     i_out = ALUOp1 >>> (ALUOp2[4:0]);
            default: i_out = {(DATA_WIDTH) {1'b0}};
        endcase

    assign branch_ctrl = {
        ALUOp1 == ALUOp2,
        1'b0,  //a useless bit just to make the decode easier
        $signed(ALUOp1) < $signed(ALUOp2),
        ALUOp1 < ALUOp2
    };
endmodule


module alu_m #(
    parameter DATA_WIDTH = 32
) (
    input  logic [DATA_WIDTH-1:0] ALUOp1,
    input  logic [DATA_WIDTH-1:0] ALUOp2,
    input  logic [           2:0] ALUctrl,
    output logic [DATA_WIDTH-1:0] m_out
);
    // just funct3 essentially
    typedef enum logic [3:0] {
        MUL   = 3'b000,
        MULH  = 3'b001,
        MULSU = 3'b010,
        MULU  = 3'b011,
        DIV   = 3'b100,
        DIVU  = 3'b101,
        REM   = 3'b110,
        REMU  = 3'b111
    } alu_opc;

    //combinations of signed and unsigned oprands
    logic [2*DATA_WIDTH - 1:0] prod_ss;
    logic [2*DATA_WIDTH - 1:0] prod_uu;
    logic [2*DATA_WIDTH - 1:0] prod_su;

    //overflow only affect signed
    //zero affect both signed and unsigned
    logic overflow;
    logic zero;

    always_comb begin
        prod_ss = $signed({{DATA_WIDTH{ALUOp1[DATA_WIDTH-1]}}, ALUOp1}) *
                  $signed({{DATA_WIDTH{ALUOp2[DATA_WIDTH-1]}}, ALUOp2});
        prod_uu = {{DATA_WIDTH{1'b0}}, ALUOp1} *
                  {{DATA_WIDTH{1'b0}}, ALUOp2};
        prod_su = $signed({{DATA_WIDTH{ALUOp1[31]}}, ALUOp1}) *
                  $signed({DATA_WIDTH{1'b0}}, ALUOp2);

        //ALUOp1 == - 2^(data_width - 1) && ALUOp2 == -1
        overflow = ALUOp1[DATA_WIDTH - 1] && (~| ALUOp1[DATA_WIDTH-2 : 0]) &&
                   ALUOp2[0] && (~| ALUOp2[DATA_WIDTH-1 : 1]);
        zero = ~|ALUOp2;

        case (ALUctrl)
            MUL:     m_out = prod_ss[DATA_WIDTH-1:0];
            MULH:    m_out = prod_ss[2*DATA_WIDTH-1 : DATA_WIDTH];
            MULSU:   m_out = prod_su[2*DATA_WIDTH-1 : DATA_WIDTH];
            MULU:    m_out = prod_uu[2*DATA_WIDTH-1 : DATA_WIDTH];
            DIV:     if(zero)          m_out = {DATA_WIDTH{1'b1}};
                     else if(overflow) m_out = {1'b1, {(DATA_WIDTH-1){1'b0}}};
                     else              m_out = $signed({{DATA_WIDTH{ALUOp1[DATA_WIDTH-1]}}, ALUOp1}) /
                                               $signed({{DATA_WIDTH{ALUOp2[DATA_WIDTH-1]}}, ALUOp2});
            DIVU:    if(zero)          m_out = {DATA_WIDTH{1'b1}};
                     else              m_out = {{DATA_WIDTH{ALUOp1[DATA_WIDTH-1]}}, ALUOp1} /
                                               {{DATA_WIDTH{ALUOp2[DATA_WIDTH-1]}}, ALUOp2};
            REM:     if(zero)          m_out = ALUOp1;
                     else if(overflow) m_out = {DATA_WIDTH{1'b0}};
                     else              m_out = $signed({{DATA_WIDTH{ALUOp1[DATA_WIDTH-1]}}, ALUOp1}) %
                                               $signed({{DATA_WIDTH{ALUOp2[DATA_WIDTH-1]}}, ALUOp2});
            REMU:    if(zero)          m_out = ALUOp1;
                     else              m_out = {{DATA_WIDTH{ALUOp1[DATA_WIDTH-1]}}, ALUOp1} %
                                               {{DATA_WIDTH{ALUOp2[DATA_WIDTH-1]}}, ALUOp2};
            default: m_out = {(DATA_WIDTH) {1'b0}};
        endcase
    end

endmodule

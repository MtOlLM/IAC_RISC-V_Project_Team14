module control_unit(
    input logic eq,
    input logic [6:0] opcode,
    input logic [14:12] funct3,
    input logic funct7_5,
    output logic [REG_ADDR_WIDTH:0]reg_write,
    output logic pc_src,
    output logic [1:0]imm_src,
    output logic ALU_control,
    output logic ALU_src
);
    logic branch;
    logic [1:0] ALU_op;

    main_decoder main_decoder(
        .ALU_op(ALU_op),
        .ALU_src(ALU_src),
        .branch(branch),
        .imm_src(imm_src),
        .opcode(opcode),
        .reg_write(reg_write)
    );

    ALU_decoder ALU_decoder(
        .ALU_control(ALU_control),
        .ALU_op(ALU_op),
        .funct3(funct3),
        .funct7_5(funct7_5),
        .opcode(opcode)
    );

    assign pc_src = eq & branch;

endmodule

module main_decoder(
    input logic [6:0] opcode,
    output logic reg_write,
    output logic [1:0]imm_src,
    output logic ALU_src,
    output logic branch,
    output logic [1:0] ALU_op
);
    always_comb begin
        reg_write = opcode[5]^opcode[4];
        branch = opcode[6];
        ALU_op = {op[4],op[6]};
        imm_src = {opcode[5] & opcode[6], opcode[5]& ~opcode[4] & ~opcode[6]};
        ALU_src = ~opcode[4] & ~opcode[6];
    end
endmodule

module ALU_decoder(
    input logic [1:0] ALU_op,
    input logic [6:0] opcode,
    input logic [14:12] funct3,
    input logic funct7_5,
    output logic [2:0] ALU_control
);
    always_comb begin
        if(ALU_op[1]) ALU_control = {1'b0, ALU_op};
        case(funct3)
            000: ALU_control = {2'b00 , opcode[5] & funct7_5};
            010: ALU_control = 3'b101;
            110: ALU_control = 3'b011;
            111: ALU_control = 3'b010;
            default: ALU_control = 3'b000;
        endcase
    end

endmodule
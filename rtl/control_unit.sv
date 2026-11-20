module control_unit (
    input  logic [  2:0] branch_ctrl,
    input  logic [  6:0] opcode,
    input  logic [14:12] funct3,
    input  logic         funct7_5,
    input  logic         funct7_0,
    output logic         reg_write,
    output logic [  1:0] pc_src,
    output logic [  2:0] imm_src,
    output logic [  4:0] ALU_control,
    output logic [  2:1] ALU_src,      //more intuitive, ALU_src[1] for op1 and ALU_src[2] for op2
    output logic [  3:0] mem_write,
    output logic [  1:0] result_src
);
    typedef enum logic [2:0] {
        I_IMM,
        S_IMM,
        B_IMM,
        U_IMM,
        J_IMM
    } imm_type;

    typedef enum logic {
        FALSE,
        TRUE
    } true_false_type;

    typedef enum logic [1:0] {
        ALU_OUT,
        MEM_OUT,
        IMM,
        INC_PC
    } result_src_type;

    localparam logic [4:0] ADD          = 4'b0_0_000;

    localparam logic [6:0] OPTYPE_R     = 7'b011_0011;
    localparam logic [6:0] OPTYPE_I     = 7'b001_0011;
    localparam logic [6:0] OPTYPE_S     = 7'b010_0011;
    localparam logic [6:0] OPTYPE_B     = 7'b110_0011;
    localparam logic [6:0] OPTYPE_LUI   = 7'b011_0111;
    localparam logic [6:0] OPTYPE_AUIPC = 7'b001_0111;
    localparam logic [6:0] OPTYPE_JALR  = 7'b110_0111;
    localparam logic [6:0] OPTYPE_I_L   = 7'b000_0011;  //load instructions
    localparam logic [6:0] OPTYPE_JAL   = 7'b110_1111;

    logic branch_jalr;

    always_comb begin
        ALU_control = {funct7_0, funct7_5, funct3};

        branch_jalr = FALSE;
        reg_write = FALSE;
        imm_src = I_IMM;
        ALU_src = {2{FALSE}};
        mem_write = {4{FALSE}};
        result_src = ALU_OUT;
        pc_src[1] = FALSE;

        case (opcode)
            OPTYPE_R: begin
                reg_write = TRUE;
            end
            OPTYPE_I: begin
                reg_write  = TRUE;
                ALU_src[2] = TRUE;
            end
            OPTYPE_S: begin
                imm_src     = S_IMM;
                ALU_src[2]  = TRUE;
                ALU_control = ADD;
                case (funct3[13:12])
                    2'b00:   w_en = 4'b0001;
                    2'b01:   w_en = 4'b0011;
                    2'b10:   w_en = 4'b1111;
                    default: w_en = 4'b0000;
                endcase
            end
            OPTYPE_B: begin
                branch_jalr = TRUE;
                imm_src     = B_IMM;
            end
            OPTYPE_I_L: begin
                reg_write   = TRUE;
                ALU_src[2]  = TRUE;
                result_src  = MEM_OUT;
                ALU_control = ADD;
            end
            OPTYPE_AUIPC: begin
                reg_write   = TRUE;
                imm_src     = U_IMM;
                ALU_src[1]  = TRUE;
                ALU_src[2]  = TRUE;
                ALU_control = ADD;
            end
            OPTYPE_LUI: begin
                reg_write  = TRUE;
                imm_src    = U_IMM;
                result_src = IMM;
            end
            OPTYPE_JALR: begin
                branch_jalr = TRUE;
                reg_write   = TRUE;
                result_src  = INC_PC;
            end
            OPTYPE_JAL: begin
                reg_write  = TRUE;
                imm_src    = J_IMM;
                result_src = INC_PC;
            end
            default: ;
        endcase

        pc_src[0] = (branch_ctrl[funct3[14:13]] ^ funct3[12]) & branch;
    end
endmodule

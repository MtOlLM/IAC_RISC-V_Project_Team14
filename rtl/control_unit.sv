module control_unit (
    input  logic [  6:0] opcode,
    input  logic [14:12] funct3,
    input  logic         funct7_5,
    output logic         reg_write,
    output logic         branch,       
    output logic         jump,         // for jal or jalr
    output logic         jalr,         // target uses rs1 instead of pc
    output logic [  2:0] imm_src,
    output logic [  3:0] ALU_control,
    output logic [  2:1] ALU_src,      //[1] for op1 and [2] for op2
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

    localparam logic [3:0] ADD          = 4'b0_000;

    localparam logic [6:0] OPTYPE_R     = 7'b011_0011;
    localparam logic [6:0] OPTYPE_I     = 7'b001_0011;
    localparam logic [6:0] OPTYPE_S     = 7'b010_0011;
    localparam logic [6:0] OPTYPE_B     = 7'b110_0011;
    localparam logic [6:0] OPTYPE_LUI   = 7'b011_0111;
    localparam logic [6:0] OPTYPE_AUIPC = 7'b001_0111;
    localparam logic [6:0] OPTYPE_JALR  = 7'b110_0111;
    localparam logic [6:0] OPTYPE_I_L   = 7'b000_0011;  //load instructions
    localparam logic [6:0] OPTYPE_JAL   = 7'b110_1111;


    always_comb begin
        ALU_control = ADD;

        reg_write = FALSE;
        imm_src = I_IMM;
        ALU_src = {2{FALSE}};
        mem_write = {4{FALSE}};
        result_src = ALU_OUT;
        branch = FALSE;
        jump = FALSE;
        jalr = FALSE;

        case (opcode)
            OPTYPE_R: begin
                reg_write = TRUE;
                ALU_control = {funct7_5, funct3};
            end
            OPTYPE_I: begin
                reg_write  = TRUE;
                ALU_src[2] = TRUE;
                ALU_control = {1'b0, funct3};
                // Only right shifts use instruction bit 30.
                if (funct3 == 3'b101) ALU_control[3] = funct7_5;
            end
            OPTYPE_S: begin
                imm_src     = S_IMM;
                ALU_src[2]  = TRUE;
                ALU_control = ADD;
                case (funct3[13:12])
                    2'b00:   mem_write = 4'b0001;
                    2'b01:   mem_write = 4'b0011;
                    2'b10:   mem_write = 4'b1111;
                    default: mem_write = 4'b0000;
                endcase
            end
            OPTYPE_B: begin
                imm_src = B_IMM;
                branch  = TRUE;     // taken/not-taken is decided in branch_unit
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
                jump       = TRUE;
                jalr       = TRUE;
                reg_write  = TRUE;
                imm_src    = I_IMM;
                result_src = INC_PC;
            end
            OPTYPE_JAL: begin
                jump       = TRUE;
                reg_write  = TRUE;
                imm_src    = J_IMM;
                result_src = INC_PC;
            end
            default: ;
        endcase

    end
endmodule

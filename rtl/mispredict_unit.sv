// the 
module mispredict_unit #(
    parameter DATA_WIDTH = 32
) (
    input  logic [           2:0] branch_ctrl,
    input  logic [           2:0] funct3E,
    input  logic                  jumpE,
    input  logic                  branchE,
    input  logic [DATA_WIDTH-1:0] alu_out,
    input  logic [DATA_WIDTH-1:0] pred_targetE,
    input  logic                  pred_takenE,
    output logic                  mispredict,
    output logic                  up_taken,
    output logic [DATA_WIDTH-1:0] up_target
);
    typedef enum logic [2:0] {
        BEQ  = 3'b000,
        BNE  = 3'b001,
        BLT  = 3'b100,
        BGE  = 3'b101,
        BLTU = 3'b110,
        BGEU = 3'b111
    } branch_type;

    always_comb begin
        up_taken  = 1'b0;
        up_target = 32'h0000_0000;

        if (branchE) begin
            case (funct3)
                BEQ:     up_taken = branch_ctrl[2];
                BNE:     up_taken = ~branch_ctrl[2];
                BLT:     up_taken = branch_ctrl[1];
                BGE:     up_taken = ~branch_ctrl[1];
                BLTU:    up_taken = branch_ctrl[0];
                BGEU:    up_taken = ~branch_ctrl[0];
                default: ;
            endcase
            up_target = alu_out;
        end

        if (jumpE) begin
            up_taken  = 1'b1;
            up_target = alu_out;
        end

        mispredict = (up_taken != pred_takenE) || (up_target != pred_targetE);
    end
endmodule

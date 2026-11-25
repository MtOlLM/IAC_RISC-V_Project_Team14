module branch_unit (
    input  logic       branch,
    input  logic       jump,
    input  logic [2:0] funct3,
    input  logic [3:0] branch_ctrl,  // from the ALU
    output logic       pc_src        // if 1 take pc_target
);
    logic taken;

    always_comb begin
        case (funct3)
            3'b000:  taken =  branch_ctrl[3];  // BEQ
            3'b001:  taken = ~branch_ctrl[3];  // BNE
            3'b100:  taken =  branch_ctrl[1];  // BLT
            3'b101:  taken = ~branch_ctrl[1];  // BGE
            3'b110:  taken =  branch_ctrl[0];  // BLTU
            3'b111:  taken = ~branch_ctrl[0];  // BGEU
            default: taken = 1'b0;
        endcase
        pc_src = jump | (branch & taken);
    end
endmodule

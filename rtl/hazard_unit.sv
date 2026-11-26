module hazard_unit #(
    parameter DATA_WIDTH = 32
) (
    input  logic [DATA_WIDTH-1:0] rs1D,
    input  logic [DATA_WIDTH-1:0] rs2D,
    input  logic [DATA_WIDTH-1:0] rs1E,
    input  logic [DATA_WIDTH-1:0] rs2E,
    input  logic [DATA_WIDTH-1:0] rdE,
    input  logic [DATA_WIDTH-1:0] rdM,
    input  logic [DATA_WIDTH-1:0] rdW,
    input  logic                  reg_writeW,
    input  logic                  reg_writeM,
    input  logic                  mem_readE,
    input  logic                  mispredictE,
    output logic [           1:0] forward1E,
    output logic [           1:0] forward2E,
    output logic                  stallF,
    output logic                  stallD,
    output logic                  flushD,
    output logic                  flushE
);
    typedef enum logic [1:0] {
        NO_FORWARD  = 2'b00,
        RESULT_W    = 2'b01,
        ALURESULT_M = 2'b10
    } forward_type;

    logic l_stall;

    always_comb begin
        //Forwarding
        //Op1
        if (reg_writeM && (rdM != 5'b0) && (rdM == rs1E)) forward1E = ALURESULT_M;
        else if (reg_writeW && (rdW != 5'b0) && (rdW == rs1E)) forward1E = RESULT_W;
        else forward1E = NO_FORWARD;

        //Op2
        if (reg_writeM && (rdM != 5'b0) && (rdM == rs2E)) forward2E = ALURESULT_M;
        else if (reg_writeW && (rdW != 5'b0) && (rdW == rs2E)) forward2E = RESULT_W;
        else forward2E = NO_FORWARD;

        //load stalls
        l_stall = mem_readE && (rdE != 5'd0) && ((rdE == rs1D) || (rdE == rs2D));

        stallF  = l_stall;
        stallD  = l_stall;

        //flushes
        flushD  = mispredictE;
        flushE  = l_stall | mispredictE;
    end
endmodule

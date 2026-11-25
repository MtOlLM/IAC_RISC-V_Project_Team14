module type_unit #(
    parameter REG_ADDR_WIDTH = 5
) (
    input  logic [REG_ADDR_WIDTH-1:0] rs1E,
    input  logic [REG_ADDR_WIDTH-1:0] rdE,
    input  logic                      jalrE,
    input  logic                      branchE,
    output logic [               2:0] up_type
);
    typedef enum logic [2:0] {
        BR_COND = 3'b000,
        BR_JUMP = 3'b001,
        BR_CALL = 3'b010,
        BR_RET  = 3'b011,
        BR_CORO = 3'b100
    } branch_type;

    logic link_rs1, link_rd;

    always_comb begin
        link_rs1 = (rs1E == REG_ADDR_WIDTH'(1)) || (rs1E == REG_ADDR_WIDTH'(5));
        link_rd  = (rdE == REG_ADDR_WIDTH'(1)) || (rdE == REG_ADDR_WIDTH'(5));

        if (branchE) up_type = BR_COND;
        else if (jalrE && link_rs1 && link_rd && rdE != rs1E) up_type = BR_CORO;
        else if (link_rd) up_type = BR_CALL;
        else if (jalrE && link_rs1) up_type = BR_RET;
        else up_type = BR_JUMP;
    end
endmodule

module regfile #(
    parameter DATA_WIDTH = 32
    parameter ADDRESS_WIDTH = 5
) (
    input   logic [ADDRESS_WIDTH-1:0]  AD1, AD2, AD3
    input   logic                      clk,
    input   logic                      WE3,
    input   logic    [DATA_WIDTH-1:0]  WD3,
    output  logic    [DATA_WIDTH-1:0]  RD1, RD2,
    output  logic                      a0,
);

    always_ff @(posedge clk)
        if(WE3 && AD3 != '0) reg[AD3] <= WE3;

    assign RD1 = reg[AD1];
    assign RD2 = reg[AD2];
endmodule

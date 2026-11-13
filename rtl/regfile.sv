module regfile #(
    parameter DATA_WIDTH = 32,
    ADDRESS_WIDTH = 5
) (
    input  logic [ADDRESS_WIDTH-1:0] AD1, AD2, AD3,
    input  logic                     clk,
    input  logic                     WE3,
    input  logic [   DATA_WIDTH-1:0] WD3,
    output logic [   DATA_WIDTH-1:0] RD1, RD2, a0
);

  logic [DATA_WIDTH-1:0] register_file[(2**ADDRESS_WIDTH)-1:0];

  initial begin
    for(int i = 0; i < (2**ADDRESS_WIDTH) ; i++) register_file[i] = 32'b0;
  end
  
  always_ff @(posedge clk) 
    if (WE3 && (AD3 != '0)) register_file[AD3] <= WD3;

  always_comb begin
    RD1 = register_file[AD1];
    RD2 = register_file[AD2];
    a0  = register_file[5'd10];
  end
endmodule

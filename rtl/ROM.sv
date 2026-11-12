module ROM#(
    parameter ADDR_WIDTH = 32,
    DATA_WIDTH = 32
)(
    input logic [ADDR_WIDTH-1 : 0] addr,
    output logic [DATA_WIDTH-1 : 0] data
);
    logic [DATA_WIDTH-1 : 0] rom_array [2**ADDR_WIDTH-1 : 0];
    initial begin
        //$readmemh("",rom_array);
    end
    assign data = rom_array[addr];
endmodule

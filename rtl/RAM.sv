module RAM #(
    parameter ADDR_WIDTH = 17  //data memory with address from 0x0000_0000 to 0x0002_0000
) (
    input  logic          clk,
    input  logic          w_en,
    input  logic [31 : 0] data_in,
    input  logic [31 : 0] addr,
    output logic [31 : 0] data_out
);
    logic [7 : 0] ram_array[2**ADDR_WIDTH-1 : 0];

    initial $readmemh("sine.mem", ram_array);

    logic [ADDR_WIDTH-1 : 0] addr_low;
    assign addr_low = addr[ADDR_WIDTH-1 : 0];

    always_ff @(posedge clk)
        if (w_en) begin
            ram_array[addr_low] <= data_in[7 : 0];
            ram_array[addr_low+ADDR_WIDTH'(1)] <= data_in[15 : 8];
            ram_array[addr_low+ADDR_WIDTH'(2)] <= data_in[23 : 16];
            ram_array[addr_low+ADDR_WIDTH'(3)] <= data_in[31 : 24];
        end

    assign data_out = {
        ram_array[addr_low+ADDR_WIDTH'(3)],
        ram_array[addr_low+ADDR_WIDTH'(2)],
        ram_array[addr_low+ADDR_WIDTH'(1)],
        ram_array[addr_low]
    };
endmodule

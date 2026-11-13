module ROM #(
    parameter ADDR_WIDTH = 16 //65 kB of ROM
) (
    input  logic [31 : 0] addr,
    output logic [31 : 0] data
);
  logic [7 : 0] rom_array[2**ADDR_WIDTH-1 : 0];
  initial $readmemh("program.hex",rom_array);
  logic [15 : 0] addr_low16;
  assign addr_low16 = addr[15 : 0];
  assign data = {rom_array[addr_low16 + ADDR_WIDTH'(3)],
                rom_array[addr_low16 + ADDR_WIDTH'(2)],
                rom_array[addr_low16 + ADDR_WIDTH'(1)],
                rom_array[addr_low16]};
endmodule

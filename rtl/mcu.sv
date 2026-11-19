module mcu #(
    parameter DATA_WIDTH = 32
) (
    input  logic                  clk,
    input  logic [           3:0] w_en,
    input  logic [           2:0] funct3,
    input  logic [DATA_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] data_in,
    output logic [DATA_WIDTH-1:0] data_out
);
    logic [DATA_WIDTH-1:0] ram_data_out;

    always_comb  //load
        case (funct3)
            3'b000:  data_out = {{(DATA_WIDTH - 8) {ram_data_out[7]}}, ram_data_out[7:0]};
            3'b001:  data_out = {{(DATA_WIDTH - 16) {ram_data_out[15]}}, ram_data_out[15:0]};
            3'b010:  data_out = ram_data_out;
            3'b100:  data_out = {{(DATA_WIDTH - 8) {1'b0}}, ram_data_out[7:0]};
            3'b101:  data_out = {{(DATA_WIDTH - 16) {1'b0}}, ram_data_out[15:0]};
            default: data_out = ram_data_out;
        endcase

    RAM data_RAM (
        .clk     (clk),
        .w_en    (w_en),
        .data_in (data_in),
        .addr    (addr),
        .data_out(ram_data_out)
    );

endmodule

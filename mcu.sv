module mcu #(
    parameter DATA_WIDTH = 32
) (
    input logic                   clk,
    input logic                   w_en,
    input logic             [2:0] funct3,
    input logic  [DATA_WIDTH-1:0] addr,
    input logic  [DATA_WIDTH-1:0] data_in,
    output logic [DATA_WIDTH-1:0] data_out
);
    logic [DATA_WIDTH-1:0] ram_data_in;
    logic [DATA_WIDTH-1:0] ram_data_out;

    always_comb begin : //store
        case(funct3[1:0]) :
            2'b00: ram_data_out = {ram_data_in[31:8], data_in[7:0]},
            2'b01: ram_data_out = {ram_data_in[31:16], data_in[15:0]},
            2'b10: ram_data_out = data_in,
            default: ram_data_out = data_in
        endcase
    end

    always_comb begin : //load
        case(funct3) :
            3'b000: data_out = {{24{ram_data_in[7]}}, ram_data_in[7:0]},
            3'b001: data_out = {{16{ram_data_in[15]}}, ram_data_in[15:0]},
            3'b010: data_out = ram_data_in,
            3'b100: data_out = {{24'b0}, ram_data_in[7:0]},
            3'b101: data_out = {{16'b0}, ram_data_in[15:0]},
            default: data_out = ram_data_in
        endcase
    end

    RAM sine_RAM (
        .clk     (clk),
        .w_en    (w_en),
        .data_in (ram_data_in),
        .addr    (addr),
        .data_out(ram_data_out)
    )

endmodule

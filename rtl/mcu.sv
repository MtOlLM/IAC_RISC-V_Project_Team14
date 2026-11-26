module mcu #(
    parameter DATA_WIDTH = 32
) (
    input  logic                  clk,
    input  logic                  rst,
    input  logic                  mem_state,
    input  logic [           3:0] w_en,
    input  logic [           2:0] funct3,
    input  logic [DATA_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] data_in,
    output logic [DATA_WIDTH-1:0] data_out
    output logic                  stall
);
    logic [DATA_WIDTH-1:0] cache_data_out;
    logic [DATA_WIDTH-1:0] ram_addr, ram_wdata, ram_rdata;
    logic            [3:0] ram_wen;

    always_comb  //load
        case (funct3)
            3'b000:  data_out = {{(DATA_WIDTH - 8) {cache_data_out[7]}}, cache_data_out[7:0]};
            3'b001:  data_out = {{(DATA_WIDTH - 16) {cache_data_out[15]}}, cache_data_out[15:0]};
            3'b010:  data_out = cache_data_out;
            3'b100:  data_out = {{(DATA_WIDTH - 8) {1'b0}}, cache_data_out[7:0]};
            3'b101:  data_out = {{(DATA_WIDTH - 16) {1'b0}}, cache_data_out[15:0]};
            default: data_out = cache_data_out;
        endcase

    cache data_cache (
        .clk         (clk),
        .rst         (rst),
        .cpu_addr    (addr),
        .cpu_data_in (data_in),
        .cpu_state   (mem_state),
        .cpu_wen     (|w_en),
        .cpu_byteen  (w_en),
        .cpu_data_out(cache_data_out),
        .stall       (stall),
        .ram_data_in (ram_rdata),
        .ram_addr    (ram_addr),
        .ram_data_out(ram_wdata),
        .ram_wen     (ram_wen)
    );

    RAM data_RAM (
        .clk     (clk),
        .w_en    (ram_wen),
        .data_in (ram_wdata),
        .addr    (ram_addr),
        .data_out(ram_rdata)
    );

endmodule

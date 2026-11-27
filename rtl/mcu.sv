module mcu #(
    parameter DATA_WIDTH = 32
) (
    input  logic                  clk,
    input  logic                  rst,
    input  logic                  enable,
    input  logic                  atomic_en,
    input  logic [           4:0] funct5,
    input  logic                  rs2_zero,
    input  logic [           3:0] w_en,
    input  logic [           2:0] funct3,
    input  logic [DATA_WIDTH-1:0] addr,
    input  logic [DATA_WIDTH-1:0] data_in,
    output logic [DATA_WIDTH-1:0] data_out,
    output logic                  fault
);
    logic [DATA_WIDTH-1:0] ram_data_out, ram_data_in;
    logic [DATA_WIDTH-1:0] atomic_result, atomic_data;
    logic [3:0] ram_wen, atomic_wen;

    atomic_unit atomic_ops (
        .clk        (clk),
        .rst        (rst),
        .enable     (enable),
        .atomic_en  (atomic_en),
        .funct5     (funct5),
        .funct3     (funct3),
        .rs2_zero   (rs2_zero),
        .addr       (addr),
        .data_in    (data_in),
        .mem_data   (ram_data_out),
        .store_en   (w_en),
        .result     (atomic_result),
        .write_data (atomic_data),
        .write_en   (atomic_wen),
        .fault      (fault)
    );

    always_comb begin
        case (funct3)
            3'b000:  data_out = {{(DATA_WIDTH - 8){ram_data_out[7]}}, ram_data_out[7:0]};
            3'b001:  data_out = {{(DATA_WIDTH - 16){ram_data_out[15]}}, ram_data_out[15:0]};
            3'b010:  data_out = ram_data_out;
            3'b100:  data_out = {{(DATA_WIDTH - 8){1'b0}}, ram_data_out[7:0]};
            3'b101:  data_out = {{(DATA_WIDTH - 16){1'b0}}, ram_data_out[15:0]};
            default: data_out = ram_data_out;
        endcase

        ram_data_in = data_in;
        ram_wen = w_en;
        if (atomic_en) begin
            data_out = atomic_result;
            ram_data_in = atomic_data;
            ram_wen = atomic_wen;
        end
        if (!enable || rst) ram_wen = 4'b0000;
    end

    RAM data_RAM (
        .clk     (clk),
        .w_en    (ram_wen),
        .data_in (ram_data_in),
        .addr    (addr),
        .data_out(ram_data_out)
    );
endmodule

module atomic_unit #(
    parameter ADDR_WIDTH = 17
) (
    input  logic        clk,
    input  logic        rst,
    input  logic        enable,
    input  logic        atomic_en,
    input  logic [4:0]  funct5,
    input  logic [2:0]  funct3,
    input  logic        rs2_zero,
    input  logic [31:0] addr,
    input  logic [31:0] data_in,
    input  logic [31:0] mem_data,
    input  logic [3:0]  store_en,
    output logic [31:0] result,
    output logic [31:0] write_data,
    output logic [3:0]  write_en,
    output logic        fault
);
    typedef enum logic [4:0] {
        AMOADD  = 5'h00,
        AMOSWAP = 5'h01,
        LR      = 5'h02,
        SC      = 5'h03,
        AMOXOR  = 5'h04,
        AMOOR   = 5'h08,
        AMOAND  = 5'h0c,
        AMOMIN  = 5'h10,
        AMOMAX  = 5'h14
    } atomic_type;

    logic reserve_valid;
    logic [ADDR_WIDTH-1:2] reserve_word;
    logic valid_op, store_hit;
    logic [ADDR_WIDTH-1:0] store_byte_addr [4];

    always_comb begin
        valid_op = 1'b1;
        case (funct5)
            LR: valid_op = rs2_zero;
            SC, AMOADD, AMOSWAP, AMOXOR, AMOOR,
            AMOAND, AMOMIN, AMOMAX: ;
            default: valid_op = 1'b0;
        endcase

        fault = atomic_en && (!valid_op || funct3 != 3'b010 ||
                              addr[1:0] != 2'b00 || (addr >> ADDR_WIDTH) != 0);
    end

    always_comb begin
        result = mem_data;
        write_data = mem_data;
        write_en = 4'b0000;

        if (atomic_en && !fault) begin
            case (funct5)
                LR: ;
                SC: begin
                    result = 32'd1;
                    if (reserve_valid && reserve_word == addr[ADDR_WIDTH-1:2]) begin
                        result = 32'd0;
                        write_data = data_in;
                        write_en = 4'b1111;
                    end
                end
                default: begin
                    // AMOs return the old word.
                    write_en = 4'b1111;
                    case (funct5)
                        AMOSWAP: write_data = data_in;
                        AMOADD:  write_data = mem_data + data_in;
                        AMOXOR:  write_data = mem_data ^ data_in;
                        AMOOR:   write_data = mem_data | data_in;
                        AMOAND:  write_data = mem_data & data_in;
                        AMOMIN:  write_data = ($signed(mem_data) < $signed(data_in))
                                             ? mem_data : data_in;
                        AMOMAX:  write_data = ($signed(mem_data) > $signed(data_in))
                                             ? mem_data : data_in;
                        default: write_en = 4'b0000;
                    endcase
                end
            endcase
        end

        if (!enable || rst) write_en = 4'b0000;
    end

    always_comb begin
        store_hit = 1'b0;
        for (int i = 0; i < 4; i++) begin
            store_byte_addr[i] = addr[ADDR_WIDTH-1:0] + ADDR_WIDTH'(i);
            if (store_en[i] && store_byte_addr[i][ADDR_WIDTH-1:2] == reserve_word)
                store_hit = 1'b1;
        end
    end

    always_ff @(posedge clk) begin
        if (rst) begin
            reserve_valid <= 1'b0;
            reserve_word <= '0;
        end else if (enable && !fault) begin
            if (atomic_en) begin
                if (funct5 == LR) begin
                    reserve_valid <= 1'b1;
                    reserve_word <= addr[ADDR_WIDTH-1:2];
                end else if (funct5 == SC) begin
                    reserve_valid <= 1'b0;
                end else if ((|write_en) && reserve_word == addr[ADDR_WIDTH-1:2]) begin
                    reserve_valid <= 1'b0;
                end
            end else if (store_hit) begin
                reserve_valid <= 1'b0;
            end
        end
    end
endmodule

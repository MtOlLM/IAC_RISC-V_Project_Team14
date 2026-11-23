// Branch Target Buffer, very similar to cache
module btb #(
    //The instruction memory has address 0xBFC00000 to 0xBFC00FFF so only the lower 12 bits are different
    parameter ADDR_WIDTH = 12,
    parameter SET_WIDTH  = 6,
    parameter WAY_WIDTH  = 1
) (
    input  logic                  clk,
    input  logic                  rst,
    //lookup
    input  logic [ADDR_WIDTH-1:2] pcF,
    output logic                  hitF,
    output logic [ADDR_WIDTH-1:2] targetF,
    output logic [           1:0] typeF,
    //update
    input  logic                  up_en,
    input  logic [ADDR_WIDTH-1:2] up_pc,
    input  logic [ADDR_WIDTH-1:2] up_target,
    input  logic [           1:0] up_type
);
    localparam ENTRIES = 2 ** SET_WIDTH;
    localparam WAYS = 2 ** WAY_WIDTH;
    localparam TAG_WIDTH = ADDR_WIDTH - SET_WIDTH - WAY_WIDTH - 2;  //2 is the byte offset

    //use different variables for different part of the buffer instead of creating a big block of memory
    //this avoids complex index calculation
    logic                  valid [ENTRIES * WAYS];
    logic [ TAG_WIDTH-1:0] tag   [ENTRIES * WAYS];
    logic [DATA_WIDTH-1:2] target[ENTRIES * WAYS];
    logic [           1:0] kind  [ENTRIES * WAYS];  // type itself is a keyword

    //f for fetch and u for update
    logic [WAY_WIDTH-1:0] way_f, way_u;
    logic [SET_WIDTH+WAY_WIDTH-1:0] set_f, set_u;
    logic [SET_WIDTH+WAY_WIDTH-1:0] idx_f, idx_u;
    logic [TAG_WIDTH-1:0] tag_f, tag_u;

    //pc[ADDR_WIDTH-1 : 2] = tag bits + set bits + way bit(s)
    always_comb begin
        way_f = pcF[WAY_WIDTH+1:2];
        set_f = pcF[SET_WIDTH+1:WAY_WIDTH+2] << WAY_WIDTH;
        idx_f = set_f + way_f;

        tag_f = pcF[ADDR_WIDTH-1:SET_WIDTH+2];

        hitF = valid[idx_f] && (tag[idx_f] == tag_f);
        targetF = target[idx_f];
        typeF = kind[idx_f];
    end

    always_comb begin
        way_u = up_pc[WAY_WIDTH+1:2];
        set_u = up_pc[SET_WIDTH+1:2] << WAY_WIDTH;
        idx_u = set_u + way_u;

        tag_u = up_pc[ADDR_WIDTH-1:SET_WIDTH+2];
    end


    always_ff @(posedge clk)
        if (rst) begin
            for (int i = 0; i < ENTRIES * WAYS; i++) valid[i] <= 1'b0;
        end else if (up_en) begin
            valid[idx_u]  <= 1'b1;
            tag[idx_u]    <= tag_u;
            target[idx_u] <= up_target;
            kind[idx_u]   <= up_type;
        end

endmodule

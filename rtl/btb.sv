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
    output logic [           2:0] typeF,
    //update
    input  logic                  up_en,
    input  logic [ADDR_WIDTH-1:2] up_pc,
    input  logic [ADDR_WIDTH-1:2] up_target,
    input  logic [           2:0] up_type
);
    localparam SETS      = 2 ** SET_WIDTH;
    localparam WAYS      = 2 ** WAY_WIDTH;
    localparam WAY_BITS  = (WAY_WIDTH > 0) ? WAY_WIDTH : 1;
    localparam IDX_BITS  = SET_WIDTH + WAY_WIDTH;            // index of the array
    localparam TAG_WIDTH = ADDR_WIDTH - SET_WIDTH - 2;

    logic                  valid [SETS*WAYS-1:0];
    logic [ TAG_WIDTH-1:0] tag   [SETS*WAYS-1:0];
    logic [ADDR_WIDTH-1:2] target[SETS*WAYS-1:0];
    logic [           2:0] kind  [SETS*WAYS-1:0];  //type itself is a keyword in SystemVerilog
    logic [  WAY_BITS-1:0] idx   [     SETS-1:0];

    logic [SET_WIDTH-1:0] set_f, set_u;
    logic [TAG_WIDTH-1:0] tag_f, tag_u;
    logic [IDX_BITS-1:0] idx_f, idx_u;
    logic                hit_u;
    logic [WAY_BITS-1:0] way_u;

    //lookup
    always_comb begin
        set_f = pcF[SET_WIDTH+1:2];
        tag_f = pcF[ADDR_WIDTH-1:SET_WIDTH+2];
        idx_f = IDX_BITS'(set_f) << WAY_WIDTH;

        hitF    = 1'b0;
        targetF = (ADDR_WIDTH-2)'(0);
        typeF   = 3'b000;

        for (int w = 0; w < WAYS; w++)
            if (valid[idx_f+IDX_BITS'(w)] && tag[idx_f+IDX_BITS'(w)] == tag_f) begin
                hitF    = 1'b1;
                targetF = target[idx_f+IDX_BITS'(w)];
                typeF   = kind[idx_f+IDX_BITS'(w)];
            end
    end

    //update
    always_comb begin
        set_u = up_pc[SET_WIDTH+1:2];
        tag_u = up_pc[ADDR_WIDTH-1:SET_WIDTH+2];
        idx_u = IDX_BITS'(set_u) << WAY_WIDTH;

        hit_u = 1'b0;
        way_u = idx[set_u];
        for (int w = 0; w < WAYS; w++)
            if (valid[idx_u+IDX_BITS'(w)] && tag[idx_u+IDX_BITS'(w)] == tag_u) begin
                hit_u = 1'b1;
                way_u = WAY_BITS'(w);
            end

        idx_u = idx_u + IDX_BITS'(way_u);
    end

    always_ff @(posedge clk)
        if (rst) begin
            for (int s = 0; s < SETS; s++) idx[s] <= '0;
            for (int i = 0; i < SETS * WAYS; i++) valid[i] <= 1'b0;
        end else if (up_en) begin
            valid[idx_u]  <= 1'b1;
            tag[idx_u]    <= tag_u;
            target[idx_u] <= up_target;
            kind[idx_u]   <= up_type;
            if (!hit_u && WAYS > 1) idx[set_u] <= idx[set_u] + WAY_BITS'(1);
        end

endmodule

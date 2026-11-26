module cache #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32,
    parameter BLOCK_SIZE = 4, // per word
    parameter CAPACITY = 4096,
    parameter WAYS = 2
) (
    input  logic                  clk,
    input  logic                  rst,
    // CPU 
    input  logic [ADDR_WIDTH-1:0] cpu_addr,
    input  logic [DATA_WIDTH-1:0] cpu_data_in,
    input  logic                  cpu_state, // if a load or store is happening
    input  logic                  cpu_wen,
    input  logic            [3:0] cpu_byteen,
    output logic [DATA_WIDTH-1:0] cpu_data_out,
    output logic                  stall,
    // MEMORY
    input  logic [DATA_WIDTH-1:0] ram_data_in,
    output logic [ADDR_WIDTH-1:0] ram_addr,
    output logic [DATA_WIDTH-1:0] ram_data_out,
    output logic            [3:0] ram_wen
);
    localparam BYTES_PER_WORD = DATA_WIDTH / 8;
    localparam BLOCK_BYTES    = BLOCK_SIZE * BYTES_PER_WORD; 
    localparam BLOCK_COUNT    = CAPACITY / BLOCK_BYTES; 
    localparam SETS           = BLOCK_COUNT / WAYS;
    localparam BYTE_OFFSET    = $clog2(BYTES_PER_WORD); 
    localparam BLOCK_OFFSET   = $clog2(BLOCK_SIZE); 
    localparam SET_INDEX      = $clog2(SETS); 
    localparam TAG            = ADDR_WIDTH - SET_INDEX - BLOCK_OFFSET - BYTE_OFFSET; 
    localparam BLOCK_LSB      = BYTE_OFFSET + BLOCK_OFFSET;

    // FSM for misses
    typedef enum logic [1:0] {IDLE, FETCH, WRITEBACK} my_state; 
    my_state state; // no split

    // CACHE
    logic                  valid [WAYS][SETS];
    logic                  dirty [WAYS][SETS];
    logic        [TAG-1:0] tag [WAYS][SETS];
    logic [DATA_WIDTH-1:0] data [WAYS][SETS][BLOCK_SIZE];
    logic                  lru [SETS]; 
    // LOOKUP - inc address
    logic  [BYTE_OFFSET-1:0] byte_off;
    logic [BLOCK_OFFSET-1:0] block_off;
    logic    [SET_INDEX-1:0] set;
    logic          [TAG-1:0] addr_tag;
    // outcomes
    logic       [WAYS-1:0] way_hit;
    logic                  hit, miss;
    logic                  way_hit_index;
    logic [DATA_WIDTH-1:0] aligned_word; // full word before alignment
    logic            [3:0] aligned_wen;
    logic [DATA_WIDTH-1:0] aligned_data_out;
    // victim
    logic           victim_way; 
    logic           victim_write_back;  
    
    logic [BLOCK_OFFSET-1:0] word_count;
    logic                    last_word; // 1 for final word
    // latch -> guarantee we refill despite cpu
    logic                  victim_q; 
    logic [ADDR_WIDTH-1:0] miss_addr_q;
    logic  [SET_INDEX-1:0] miss_set;
    logic        [TAG-1:0] miss_tag;


    always_ff @(posedge clk) begin
        if (rst) begin // reset V and D
            state      <= IDLE;
            word_count <= '0;
            for (int i = 0; i < WAYS; i++) begin
                for (int j = 0; j < SETS; j++) begin
                    valid[i][j] <= 1'b0;
                    dirty[i][j] <= 1'b0;
                end
            end
            for (int i = 0; i < SETS; i++) begin
                lru[i] <= 1'b0;
            end
        end else begin
            case (state)
                IDLE: begin
                    if (cpu_state && hit) begin // hit success
                        lru[set] <= ~way_hit_index;
                        if (cpu_wen) begin
                            for (int i = 0; i < 4; i++)
                                if (aligned_wen[i])
                                    data[way_hit_index][set][block_off][8*i +: 8] <= aligned_data_out[8*i +: 8];
                            dirty[way_hit_index][set] <= 1'b1;
                        end
                    end else if (miss) begin // miss -> store latch
                        victim_q    <= victim_way;
                        miss_addr_q <= cpu_addr;
                        word_count         <= '0;
                        state       <= victim_write_back ? WRITEBACK : FETCH;
                    end
                end

                WRITEBACK: begin
                    if (last_word) begin
                        dirty[victim_q][miss_set] <= 1'b0;
                        word_count <= '0;
                        state      <= FETCH;
                    end else begin
                        word_count <= word_count + 1'b1;
                    end
                end

                FETCH: begin
                    data[victim_q][miss_set][word_count] <= ram_data_in; // insert
                    if (last_word) begin // filling details
                        valid[victim_q][miss_set]       <= 1'b1;
                        tag  [victim_q][miss_set]       <= miss_tag;
                        dirty[victim_q][miss_set]       <= 1'b0;
                        lru  [miss_set]                 <= ~victim_q; 
                        word_count   <= '0;
                        state        <= IDLE;
                    end else begin
                        word_count <= word_count + 1'b1;
                    end
                end

                default: begin
                    word_count <= '0;
                    state      <= IDLE;
                end
            endcase
        end
    end

    always_comb begin
        // Slice inc address into desired components
        byte_off   = cpu_addr[0 +: BYTE_OFFSET];
        block_off  = cpu_addr[BYTE_OFFSET +: BLOCK_OFFSET];
        set        = cpu_addr[BYTE_OFFSET + BLOCK_OFFSET +: SET_INDEX];
        addr_tag   = cpu_addr[ADDR_WIDTH-1 -: TAG];

        // Look up in set
        for (int i = 0; i < WAYS; i++) begin
            way_hit[i] = valid[i][set] && (tag[i][set] == addr_tag);
        end

        hit  = |way_hit;
        miss = cpu_state && !hit;

        // the byte we want.
        way_hit_index    = way_hit[1];   
        aligned_word     = data[way_hit_index][set][block_off];
        cpu_data_out     = aligned_word   >> (8 * byte_off);
        aligned_wen      = cpu_byteen     << byte_off;
        aligned_data_out = cpu_data_in << (8 * byte_off);

        // where to throw new 
        if      (!valid[0][set]) victim_way = 1'b0;
        else if (!valid[1][set]) victim_way = 1'b1;
        else                     victim_way = lru[set];

        victim_write_back = valid[victim_way][set] && dirty[victim_way][set];

        last_word = (word_count == BLOCK_OFFSET'(BLOCK_SIZE-1)); // as shown in diagram
        miss_set  = miss_addr_q[BLOCK_LSB +: SET_INDEX];
        miss_tag  = miss_addr_q[ADDR_WIDTH-1 -: TAG];

        // to main mem
        ram_addr     = '0;
        ram_data_out = '0;
        ram_wen      = 4'b0000; 

        case (state)
            WRITEBACK: begin
                ram_addr  = {tag[victim_q][miss_set], miss_set, word_count, {BYTE_OFFSET{1'b0}}};
                ram_data_out = data[victim_q][miss_set][word_count];
                ram_wen   = 4'b1111;
            end
            FETCH: begin
                ram_addr  = {miss_addr_q[ADDR_WIDTH-1:BLOCK_LSB], word_count, {BYTE_OFFSET{1'b0}}};
            end
            default: ;
        endcase

        stall = (state != IDLE) || miss;
    end

endmodule

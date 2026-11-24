// Bimodal predictor
module bht #(
    parameter ADDR_WIDTH = 12,
    parameter SET_WIDTH  = 9
) (
    input  logic                  clk,
    input  logic                  rst,
    //lookup (fetch stage)
    input  logic [ADDR_WIDTH-1:2] pcF,
    output logic                  takenF,
    //update (execute stage)
    input  logic                  up_en,
    input  logic [ADDR_WIDTH-1:2] up_pc,
    input  logic                  up_taken
);
    localparam ENTRIES = 2 ** ADDR_WIDTH;

    logic [1:0] counter[ENTRIES];

    logic [SET_WIDTH-1:0] idx_f, idx_u;

    assign idx_f  = pcF[SET_WIDTH+1:2];
    assign idx_u  = up_pc[SET_WIDTH+1:2];

    assign takenF = counter[idx_f][1];

    always_ff @(posedge clk)
        if (rst) begin
            for (int i = 0; i < ENTRIES; i++)
                //initialise to weak not taken
                counter[i] <= 2'b01;
        end
        else if (up_en) begin
            if (up_taken && (~&counter[idx_u]))
                counter[idx_u] <= counter[idx_u] + 2'b01;
            else if (!up_taken && (|counter[idx_u]))
                counter[idx_u] <= counter[idx_u] - 2'b01;
        end
endmodule

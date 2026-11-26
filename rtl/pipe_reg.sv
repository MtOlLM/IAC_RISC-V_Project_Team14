// Generic pipeline register
module pipe_reg #(
    parameter WIDTH = 32
) (
    input  logic             clk,
    input  logic             rst,
    input  logic             en,    // 0 = stall
    input  logic             clr,   // 1 = flush
    input  logic [WIDTH-1:0] d,
    output logic [WIDTH-1:0] q
);
    always_ff @(posedge clk)
        if (rst || clr) q <= '0;
        else if (en)    q <= d;
endmodule

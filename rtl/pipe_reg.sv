// Generic pipeline register
module pipe_reg #(
    parameter WIDTH = 32
) (
    input  logic             clk,
    input  logic             rst,
    input  logic             stall,
    input  logic             flush,
    input  logic [WIDTH-1:0] d,
    output logic [WIDTH-1:0] q
);
    always_ff @(posedge clk)
        if (rst || flush) q <= '0;
        else if (!stall)    q <= d;
endmodule

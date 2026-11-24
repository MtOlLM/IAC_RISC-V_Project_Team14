// Return Address Stack: circular buffer, overflow overwrites the oldest entry
module ras #(
    parameter ADDR_WIDTH = 12,
    parameter PTR_WIDTH  = 4
) (
    input  logic                  clk,
    input  logic                  rst,
    // speculative ops (fetch stage)
    input  logic                  push,
    input  logic                  pop,
    input  logic [ADDR_WIDTH-1:2] push_addr,
    output logic [ADDR_WIDTH-1:2] top,
    output logic [ PTR_WIDTH-1:0] ptr,
    // repair (execute stage, on mispredict)
    input  logic                  restore,
    input  logic [ PTR_WIDTH-1:0] restore_ptr,
    input  logic                  restore_push,
    input  logic                  restore_pop,
    input  logic [ADDR_WIDTH-1:2] restore_addr
);
    localparam ENTRIES = 2 ** PTR_WIDTH;

    // ptr points to the next free slot, so the top is one below it
    logic [ADDR_WIDTH-1:2] stack[ENTRIES];

    assign top = stack[ptr-PTR_WIDTH'(1)];

    always_ff @(posedge clk)
        if (rst) ptr <= PTR_WIDTH'(0);
        else if (restore) begin  // repair has higher priority than the wrong-path fetch
            if (restore_push & restore_pop) begin
                stack[restore_ptr-PTR_WIDTH'(1)] <= restore_addr;
                ptr                              <= restore_ptr;
            end
            else if (restore_push) begin
                stack[restore_ptr] <= restore_addr;
                ptr                <= restore_ptr + PTR_WIDTH'(1);
            end
            else if (restore_pop) 
                ptr <= restore_ptr - PTR_WIDTH'(1);
            else
                ptr <= restore_ptr;
        end
        else if (push & pop) begin
            stack[ptr-PTR_WIDTH'(1)] <= push_addr; //overwrite the current top without changing the ptr
        end
        else if (push) begin
            stack[ptr] <= push_addr;
            ptr        <= ptr + PTR_WIDTH'(1);
        end
        else if (pop)
            ptr <= ptr - PTR_WIDTH'(1);

endmodule

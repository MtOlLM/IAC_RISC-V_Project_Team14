module fetch_decode_reg (
    input  logic        clk,
    input  logic        rst,
    input  logic        en,         // 0 = stall: hold
    input  logic        clr,        // 1 = flush: bubble
    input  logic [31:0] instrF,
    input  logic [31:0] pcF,
    input  logic [31:0] pc_plus4F,
    output logic [31:0] instrD,
    output logic [31:0] pcD,
    output logic [31:0] pc_plus4D,
    output logic        validD
);
    always_ff @(posedge clk)
        if (rst || clr) begin
            instrD    <= '0;        // opcode 0 -> control unit defaults -> acts as nop
            pcD       <= '0;
            pc_plus4D <= '0;
            validD    <= 1'b0;
        end else if (en) begin
            instrD    <= instrF;
            pcD       <= pcF;
            pc_plus4D <= pc_plus4F;
            validD    <= 1'b1;      // a real instruction just entered
        end
endmodule

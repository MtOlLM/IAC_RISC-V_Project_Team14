module sign_ext#(
    parameter OUTPUT_WIDTH = 32
)(
    input logic [31:7] in,
    input logic [1:0] imm_src,
    output logic [OUTPUT_WIDTH-1:0] out
);
    logic [11:0] data;
    always_comb begin
        if(imm_src[1]) data = {in[31],in[7],in[30:25],in[11:8]};
        else if(imm_src[0]) data = {in[31:25],in[11:7]};
        else data = {in[31:20]};
        out = {{(OUTPUT_WIDTH-12){data[11]}},data};
    end
endmodule

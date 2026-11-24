// Branch predictor: BTB + BHT(bimodal) + RAS

//BTB type encoding:
//  3'b000  BR_COND    conditional branch
//  3'b001  BR_JUMP    jal / jalr that is not a call or return
//  3'b010  BR_CALL    stack push
//  3'b011  BR_RET     stack pop
//  3'b100  BR_CORO stack pop and push (coroutine)
module bpu #(
    parameter DATA_WIDTH = 32,  //complete instruction/data/address width
    parameter ADDR_WIDTH = 12,  //width of bits in address used for instruction memory, including the byte offset
    parameter logic [DATA_WIDTH-ADDR_WIDTH-1:0] ADDR_PREFIX = 20'hBFC0_0,
    parameter BTB_SET_WIDTH = 6,
    parameter BTB_WAY_WIDTH = 1,
    parameter BHT_SET_WIDTH = 8,
    parameter RAS_PTR_WIDTH = 4
) (
    input  logic                     clk,
    input  logic                     rst,
    // fetch stage
    input  logic                     fetch_en,      //if advances this cycle (not stalled)
    input  logic [   DATA_WIDTH-1:0] pcF,
    output logic                     pred_takenF,
    output logic [   DATA_WIDTH-1:0] pred_targetF,
    output logic [RAS_PTR_WIDTH-1:0] ras_ptrF,
    // execute stage
    input  logic                     up_en,         // valid branch/jump in execution stage
    input  logic [   DATA_WIDTH-1:0] up_pc,
    input  logic [              2:0] up_type,
    input  logic                     up_taken,
    input  logic [   DATA_WIDTH-1:0] up_target,
    input  logic                     mispredict,
    input  logic [RAS_PTR_WIDTH-1:0] up_ras_ptr     // ras_ptrF carried with the instruction
);
    typedef enum logic [2:0] {
        BR_COND = 3'b000,
        BR_JUMP = 3'b001,
        BR_CALL = 3'b010,
        BR_RET  = 3'b011,
        BR_CORO = 3'b100
    } branch_type;

    logic                  btb_hit;
    logic [ADDR_WIDTH-1:2] btb_target;
    logic [           2:0] btb_type;
    logic                  bht_taken;
    logic [ADDR_WIDTH-1:2] ras_top;
    logic ras_push, ras_pop;

    always_comb begin
        pred_takenF  = 1'b0;
        pred_targetF = {ADDR_PREFIX, btb_target, 2'b00};
        ras_push     = 1'b0;
        ras_pop      = 1'b0;

        if (btb_hit)
            case (btb_type)
                BR_COND: pred_takenF = bht_taken;
                BR_JUMP: pred_takenF = 1'b1;
                BR_CALL: begin
                    pred_takenF = 1'b1;
                    ras_push    = fetch_en;
                end
                BR_RET: begin
                    pred_takenF  = 1'b1;
                    pred_targetF = {ADDR_PREFIX, ras_top, 2'b00};
                    ras_pop      = fetch_en;
                end
                BR_CORO: begin
                    pred_takenF  = 1'b1;
                    pred_targetF = {ADDR_PREFIX, ras_top, 2'b00};
                    ras_push     = fetch_en;
                    ras_pop      = fetch_en;
                end
                default: ;
            endcase
    end

    btb #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .SET_WIDTH (BTB_SET_WIDTH),
        .WAY_WIDTH (BTB_WAY_WIDTH)
    ) branch_target_buffer (
        .clk      (clk),
        .rst      (rst),
        .pcF      (pcF[ADDR_WIDTH-1:2]),
        .hitF     (btb_hit),
        .targetF  (btb_target[ADDR_WIDTH-1:2]),
        .typeF    (btb_type),
        .up_en    (up_en && up_taken),           //recorded only when a branch is taken
        .up_pc    (up_pc[ADDR_WIDTH-1:2]),
        .up_target(up_target[ADDR_WIDTH-1:2]),
        .up_type  (up_type)
    );

    bht #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .SET_WIDTH (BHT_SET_WIDTH)
    ) branch_history_table (
        .clk     (clk),
        .rst     (rst),
        .pcF     (pcF[ADDR_WIDTH-1:2]),
        .takenF  (bht_taken),
        .up_en   (up_en && up_type == BR_COND),
        .up_pc   (up_pc[ADDR_WIDTH-1:2]),
        .up_taken(up_taken)
    );

    ras #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .PTR_WIDTH (RAS_PTR_WIDTH)
    ) return_address_stack (
        .clk         (clk),
        .rst         (rst),
        .push        (ras_push),
        .pop         (ras_pop),
        .push_addr   (pcF[ADDR_WIDTH-1:2] + (ADDR_WIDTH - 2)'(1)),
        .top         (ras_top),
        .ptr         (ras_ptrF),
        .restore     (mispredict),
        .restore_ptr (up_ras_ptr),
        .restore_push(up_en && up_type == BR_CALL),
        .restore_pop (up_en && up_type == BR_RET),
        .restore_addr(up_pc[ADDR_WIDTH-1:2] + (ADDR_WIDTH - 2)'(1))
    );

endmodule

.text

main: 
    JAL     ra, test_eq_ne
    JAL     ra, test_signed_br
    JAL     ra, test_unsigned_br
    ADDI    a0, zero, 1
forever:
    J       forever

test_eq_ne: 
    LI      t0, 10
    LI      t1, 10
    LI      t2, 5
    BEQ     t0, t1, _beq_taken 
    J       fail
_beq_taken:
    BEQ     t0, t2, fail 
    BNE     t0, t2, _bne_taken 
    J       fail
_bne_taken:
    BNE     t0, t1, fail 
    RET

test_signed_br: 
    LI      t0, -5
    LI      t1, 5
    BLT     t0, t1, _blt_taken 
    J       fail
_blt_taken:
    BLT     t1, t0, fail 
    BGE     t1, t0, _bge_taken 
    J       fail
_bge_taken:
    BGE     t0, t1, fail 
    RET

test_unsigned_br: 
    LI      t0, -5 
    LI      t1, 5 
    BLTU    t1, t0, _bltu_taken 
    J       fail
_bltu_taken:
    BLTU    t0, t1, fail 
    BGEU    t0, t1, _bgeu_taken 
    J       fail
_bgeu_taken:
    BGEU    t1, t0, fail 
    RET

fail:
    ADDI    a0, zero, 0
    J       forever
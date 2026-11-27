.text

main: 
    JAL     ra, test_slt
    JAL     ra, test_sltu
    ADDI    a0, zero, 1
forever:
    J       forever

test_slt: 
    LI      t0, -1 
    LI      t1, 1
    SLT     t2, t0, t1 
    ADDI    t3, zero, 1
    BNE     t2, t3, fail

    SLT     t4, t1, t0
    BNE     t4, zero, fail

    SLTI    t5, t1, -1 
    BNE     t5, zero, fail
    RET

test_sltu:
    LI      t0, -1 
    LI      t1, 1
    SLTU    t2, t1, t0 
    ADDI    t3, zero, 1
    BNE     t2, t3, fail

    SLTU    t4, t0, t1 
    BNE     t4, zero, fail

    SLTIU   t5, t1, -1 
    BNE     t5, t3, fail
    RET

fail:
    ADDI    a0, zero, 0
    J       forever
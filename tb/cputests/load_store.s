.text
.equ base_buf, 0x100

main:  
    JAL     ra, test_word
    JAL     ra, test_half
    JAL     ra, test_byte
    ADDI    a0, zero, 1
forever:
    J       forever

test_word: 
    LI      a1, base_buf
    LI      t0, 0x11223344
    SW      t0, 0(a1)
    LW      t1, 0(a1) 
    BNE     t0, t1, fail
    RET

test_half: 
    LI      a1, base_buf
    LI      t0, 0x00008000
    SH      t0, 4(a1) 
    LH      t1, 4(a1)  
    LI      t2, 0xFFFF8000
    BNE     t1, t2, fail

    LHU     t3, 4(a1) 
    BNE     t3, t0, fail
    RET

test_byte: 
    LI      a1, base_buf
    LI      t0, 0x00000080
    SB      t0, 8(a1) 
    LB      t1, 8(a1) 
    LI      t2, 0xFFFFFF80
    BNE     t1, t2, fail

    LBU     t3, 8(a1) 
    BNE     t3, t0, fail

    LI      t4, 0xAABBCCDD 
    SW      t4, 12(a1)
    LI      t5, 0x99
    SB      t5, 13(a1)
    LW      t6, 12(a1)
    LI      a2, 0xAABB99DD
    BNE     t6, a2, fail
    RET

fail:
    ADDI    a0, zero, 0
    J       forever
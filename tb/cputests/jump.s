.text
# troubleshot
main:
    JAL     t0, _jal_target 
_after_jalr:
    JAL     t2, _sub_jump 
_after_sub:
    ADDI    a0, zero, 1 
forever:
    J       forever

_jal_target:
    ADDI    t0, t0, 1 
    JALR    t1, t0, 0 
    J       fail 

_sub_jump:
    JALR    zero, t2, 0 

fail:
    ADDI    a0, zero, 0
    J       forever
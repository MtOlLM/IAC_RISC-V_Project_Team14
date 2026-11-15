.text
.globl main
main:
    addi    t1, zero, 0x100     # t1 = 256
    addi    a0, zero, 0x0       # output = 0
mloop:
    addi    a1, zero, 0x0       # i = 0
iloop:
    lw      a0, 0(a1)           # a0 = mem[a1]
    addi    a1, a1, 1           # i++
    bne     a1, t1, iloop       # if i != 256 goto iloop
    bne     t1, zero, mloop     # if t1 != 0 (hint: ALWAYS) goto mloop

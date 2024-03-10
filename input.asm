.data
    .word 1 2  3 4

.text  

hello:
    jal x1 100  
    beq x1 x2 20
    beq x1 x2 who
    bne x6 x7 hell
    jalr x1 x7 who
    addi x0 x0 56
    addi x0 x0 56
    addi x0 x0 56



who:  

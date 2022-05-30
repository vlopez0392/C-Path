.data
.align 4
# test pattern 1
polynomialA: .word 5, 0, 10, 6
polynomialB: .word 1, 2, 4
ASize: .word 4
BSize: .word 3
# test pattern 2
#polynomialA: .word 1, 3, 7, 4
#polynomialB: .word 1, 0, 2, 5
#ASize: .word 4
#BSize: .word 4
# additional test pattern
#polynomialA: .word 1, 2, 3, 0, 5, 0, 3 ,1, 1
#polynomialB: .word 3, -5, 2 4
#ASize: .word 9
#BSize: .word 4
str1: .string "Product polynomial is "
str2: .string "x^"
str3: .string " + "

.text
.global _start
_start:
    la a0, polynomialA
    la a1, polynomialB
    lw a3, ASize 
    lw a4, BSize 
    jal initStack
    jal multiplyPoly
    jal printPoly
    
    exit: 
        li a7,10 
        ecall
        
multiplyPoly: 
    mv sp, a2
    mv t4, zero
    mv t0, zero ##Outer loop index
    outer: 
        lw t2, 0(a0)
        la a1, polynomialB 
        mv t5, zero
        mv,t1, zero ##Inner loop index 
        inner:
        lw t3, 0(a1)
        add t6, t4,t5
        mul t3, t2,t3
        add sp, sp, t6
        lw t6, 0(sp)
        add t3, t3,t6
        sw t3, 0(sp)
        mv sp, a2
        
        beq t1,a4, outerContinue
        addi,t1,t1,1
        addi a1,a1,4
        slli t5, t1,2
        jal zero, inner
    
        outerContinue:
        beq t0,a3,L1
        addi, t0,t0,1
        addi a0,a0,4
        slli t4, t0,2
        jal zero, outer
    L1:
    mv sp, a2
    jr ra


initStack:  #Initialize stack to hold multiplication results    
    addi a3, a3, -1
    addi a4, a4, -1
    add a6,a3,a4 #Size of resulting polynomial will be held in a6
    mv t1,zero 
    slli a5, a6, 2   #a5:Necessary space for the stack in bytes
    sub sp,sp,a5
    mv a2,sp         
    loop:
        sw zero, 0(sp)
        beq t1,a6, L2
        addi sp,sp,4
        addi t1,t1,1
        jal zero, loop
    L2:
        jr ra
        
printPoly:
    la a0, str1
    li a7, 4
    ecall

    mv t0, zero
    printLoop:
        lw a0, 0(sp)
        li a7, 1
        ecall
        
        beq t0,zero, skipPow
        la a0, str2
        li a7, 4
        ecall
        
        mv a0,t0
        li a7, 1
        ecall
        
        skipPow:
        beq t0, a6, skipAdd
        la a0, str3
        li a7, 4
        ecall
        
        skipAdd:
        beq t0,a6 L3
        addi t0,t0,1
        addi sp,sp,4
        jal zero, printLoop
    L3:
        jr ra
        
    
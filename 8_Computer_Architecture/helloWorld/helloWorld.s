.text
_start: addi a0, x0,4
       la a1, helloworld
       ecall

.data 
helloworld: .string "Hello World!\n"


#include <8051.h>

__data __at (0x30) static unsigned char test;

void testP(char p){
    __asm
        push dpl;; push low byte of p
        push _test;
    __endasm;
}

void main()
{   
    SP = 0x40;
    test = 0x31;
    testP(0x32);
}

void _sdcc_gsinit_startup(void) {
    main();
}
void _mcs51_genRAMCLEAR(void) { }
void _mcs51_genXINIT(void) { }
void _mcs51_genXRAMCLEAR(void) { }
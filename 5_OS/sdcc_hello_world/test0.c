#include <8051.h>

void main(void){
    P1 = 0x24;
}

void _sdcc_gsinit_startup(void) { main(); }
void _mcs51_genRAMCLEAR(void) {}
void _mcs51_genXINIT(void) {}
void _mcs51_genXRAMCLEAR(void) {}


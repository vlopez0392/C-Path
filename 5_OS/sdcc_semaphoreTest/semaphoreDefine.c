#include <8051.h>

__data __at (0x36) static char empty;  //semaphore s
__data __at (0x37) static char full;   //n buffers
__data __at (0x38) static char mutex;  //mutex lock
__data __at (0x39) static char n;      //Semaphore initializer

//ACC.7 - ACC BIT 7 -> Address 0E7H
//IE - EA BIT -> 0AFH

#define CNAME(s) _ ## s
#define LABELNAME(label) label ## $

//Create semaphore
#define SemaphoreCreate(s, n){ \
        __asm\
            CLR 0xAF\
            MOV CNAME(s), CNAME(n)\
            SETB 0xAF \
        __endasm;         \
}   

//Semaphore Signal
#define SemaphoreSignal(s){ \
        __asm\
            INC CNAME(s)  \
        __endasm;         \
}   

//Semaphore wait body 
#define SemaphoreWaitBody(s, label){\
    __asm\
        LABELNAME(label): MOV ACC, CNAME(s)\
                          JZ LABELNAME(label)\
                          JB 0xE7, LABELNAME(label)\
                          DEC CNAME(s)\
    __endasm;\
}

#define SemaphoreWait(s){\
    SemaphoreWaitBody(s, __COUNTER__)\
}

void main(){
    n = 1; SemaphoreCreate(mutex, n);
    n = 3; SemaphoreCreate(empty, n); 
    n = 0; SemaphoreCreate(full,n);
    
    while(1){
        SemaphoreWait(empty);
    }
}

void _sdcc_gsinit_startup(void) {
    main();
}
void _mcs51_genRAMCLEAR(void) { }
void _mcs51_genXINIT(void) { }
void _mcs51_genXRAMCLEAR(void) { }


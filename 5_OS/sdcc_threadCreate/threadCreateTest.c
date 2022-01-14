#include <8051.h>
#include "cooperative.h"

//Thread manager globals 
__data __at (0x32) unsigned static char SPArray[MAXTHREADS]; //Stack pointer array
__data __at (0x36) unsigned static char currThr;             //Current Active Thread 
__data __at (0x37) unsigned static char threadBitMask;       //Thread bitMask
//Other temporaries
__data __at (0x21) unsigned static char pushZero = 0x0;    //Direct address to push 0 to registers in ThreadCreate                     //Thread ID 
__data __at (0x38) unsigned static char tempBitMask;       //Temporary threadbitmask
__data __at (0x39) unsigned static char tempSP;            //Temporary stack pointer
__data __at (0x3A) unsigned static char startingSP;        //Starting stack pointer 
__data __at (0x3B) unsigned static char tempPSW;           //Temporal PSW

//SAVESTATE AND RESTORESTATE macros 
//SAVESTATE
#define SAVESTATE { \
        __asm\
            PUSH ACC\
            PUSH  B        \
            PUSH  DPL      \
            PUSH  DPH      \
            PUSH  PSW      \
        __endasm;         \
        SPArray[currThr] = SP; \
}   
//RESTORESTATE 
#define RESTORESTATE {   \
        SP = SPArray[currThr];  \
        __asm                   \
            POP PSW             \
            POP DPH             \
            POP DPL             \
            POP B               \
            POP ACC             \
        __endasm;               \
}

//ThreadCreate 
ThreadID ThreadCreate(void){
    //Max number of threads reached 
    if(threadBitMask == 0b1111){
        return -1;
    }   

    //Update bitmask - Sets the rightmost unset bit
    threadBitMask |= ((threadBitMask+1)&(~threadBitMask));

    //Find a threadID not in use
    ThreadID threadId = 0;
    tempBitMask = threadBitMask;
    while(tempBitMask>>=1){
        threadId++;
    }

    //Calculate starting point of SP 
    startingSP = (threadId^(1UL<<2))<<4;

    //Save current stack pointer in a temporary SP and set SP to starting SP
    tempSP = SP; 
    SP = startingSP;

    //Select appropriate PSW bank by shifting the threadID value
    tempPSW = threadId<<3;

    //Write current SP to SPArray
    SPArray[threadId] = SP;

    //Set current SP to saved SP    
    SP = tempSP;

    //Return threadID
    return threadId;
}

//ThreadYield 
void ThreadYield(void) {
    SAVESTATE;
    //Round-robin scheduling policy - Choose next thread available
    do{
        if((0b0001<<(((currThr+1)%MAXTHREADS))) & threadBitMask){
            currThr = (currThr+1)%MAXTHREADS;
            break;
        }
        currThr = (currThr+1)%MAXTHREADS;
    }while(1);
    RESTORESTATE;
}

void main(void) {
    threadBitMask = 0b0001;
    currThr = ThreadCreate();
}

//Start-up code, jump to Bootstrap in cooperative.c
void _sdcc_gsinit_startup(void) {
    main();
}
void _mcs51_genRAMCLEAR(void) { }
void _mcs51_genXINIT(void) { }
void _mcs51_genXRAMCLEAR(void) { }
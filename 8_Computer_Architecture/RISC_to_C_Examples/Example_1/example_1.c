/*
    This program translates the RISC-V assembly code into an equivalent C Program.
    Victor D. Lopez 3/26/2022
*/

// Assembly Code
// addi x6, x0, 100 	  // i = 100;
// addi x29, x0, 0 	      // Does nothing in C. Could say int j = 0 but not necessary 
// LOOP: ld x7, 0(x10)    //  Get A[0] and store in register x7
// add x5, x5, x7         // result = result + *mem
// addi x10, x10, 8       // mem++ gets next array value 
// addi x6, x6, -4 	      //  i = i - 4;
// bgt x6, x29, LOOP      //  Test loop condition ( i > 0)

#include <stdio.h> 
//Solution assumes sizeof(int) = 8 bytes
int main(void){
    int MemArray[100];
    int memArraySize = (int)(sizeof(MemArray)/sizeof(int));

    //Fill the array from integers from 1 to n
    for(int j = 0; j< memArraySize ; j++){
        MemArray[j] = j;
    }

    int * mem = MemArray;  
	int result = 0; 
	int i = 100; 

    while(i > 0){	
        result = result + *mem++; //We assume we never go out of 
                                  // bounds in array memArray.
        printf("%d: %d \n", i, result);
        i = i - 4;
        
    }
    printf("%d \n", *mem);
    printf("%d \n", result);
	return 1;
}

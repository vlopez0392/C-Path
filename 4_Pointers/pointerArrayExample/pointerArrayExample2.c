#include <stdio.h>
#include <string.h>

int main(void){
    //This program demonstrates the effect of adding an integer value to a pointer.
    long multiple[] = {15L, 25L, 35L, 35L};
    long *p = multiple;

    for(int i = 0; i<sizeof(multiple)/sizeof(multiple[0]); ++i){
        printf("Address p+%d (&multiple[%d]) %p, *(p+%d) value:%ld\n", i,i, (p+i), i, *(p+i));    
    }
    
    //In this system the size of long is: 
    printf("Size of long data type in this system: %d bytes",(int)sizeof(long));
    return 0;
}
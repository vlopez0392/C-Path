/* getStringLength.c
* This program calculates the length of a string using pointers using only pointer arithmetic.
* The function getStringLength() gets a constant char pointer as a parameter
*/

#include <stdio.h>
int getStringLength(char * const charArray );

int main(void){
    int length; 
    char countMe[] = "HELLO"; //5
    char countMe2[] = "Hello, my name is Vick"; //22
    
    length = getStringLength(countMe);
    printf("The length of %s is %d \n", countMe, length);

    length = getStringLength(countMe2);
    printf("The length of %s is %d \n", countMe, length);
    return 0;
}

int getStringLength(char * const charArray){
    char * ptr = charArray; 
    char * charEnd; 

    while(*ptr){
        ptr++;
    }
    charEnd = ptr;
    return charEnd - &charArray[0];
}

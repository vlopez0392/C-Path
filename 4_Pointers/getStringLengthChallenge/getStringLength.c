/* getStringLength.c
* This program calculates the length of a string using pointers using only pointer arithmetic.
* The function getStringLength() gets a constant char pointer as a parameter
*/

#include <stdio.h>
int getStringLength(const char *charArray );

int main(void){
    int length; 
    char countMe[] = "HELLO"; //5
    char countMe2[] = "Hello, my name is Vick"; //22
    char imZeroLength[] = "";
    
    length = getStringLength(countMe);
    printf("The length of %s is %d \n", countMe, length);

    length = getStringLength(countMe2);
    printf("The length of %s is %d \n", countMe2, length);

    length = getStringLength(imZeroLength);
    printf("The length of zero length is %d \n", length);

    return 0;
}

int getStringLength(const char * charArray){
    const char * charEnd = charArray; 

    while(*charEnd){
        charEnd++;
    }
    return charEnd - &charArray[0];
}



#include <stdio.h> 
#include <stdlib.h>

int main(void){
    /* Challenge
    * Write a program that creates an integer variable with a hard-coded value. Assign that variable's 
    * address to a pointer variable.
    * 
    * Display as output the address of the pointer, the value of the pointer, and the value of what the 
    * pointer is pointing to.  
    */

    int number = 100; 
    int * pnumber = &number; 

    printf("Value of the hard-coded value: %d \n", number);
    printf("Address value of the hard-coded value: %p \n", &number);
    
    printf("The address of the pointer is: %p \n", (void *) &pnumber);
    printf("The value of the pointer is: %p \n", pnumber);
    printf("The value of what the pointer is pointing to is: %d \n", *pnumber);

    return 0;
}
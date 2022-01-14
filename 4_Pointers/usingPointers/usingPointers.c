#include <stdio.h>

int main(void){
    /*  Note 1: The value referenced by a pointer can be used in arithmetic expressions
    *     * If  a variable is defined to be of type "pointer to integer" then it is evaluated using the rules 
    *       of integer arithmetic
    */
    int number = 0;
    int *pnumber = NULL; 
    number = 10;
    pnumber = &number; 

    *pnumber +=25;

    printf("The value of number is: %d \n", number);
    printf("The value in the address pointed by the pointer is: %d \n" , *pnumber);

   //Example 2 - Using a single pointer to change the values of several variables
    long num1 = 0L;
    long num2 = 0L;
    long *pnum = NULL;

    pnum = &num1;
    *pnum = 2L; //Value of num1 is 2L - We use the derefence operator * to modify this value
    ++num2; //Value of num2 is 1L
    num2 +=*pnum; //Value of num2 is 3L

    pnum = &num2; 
    ++*pnum; //Value of num2 is 4L

    printf("num1 = %ld num2 = %ld *pnum = %ld *pnum + num2 = %ld\n", num1, num2, *pnum, *pnum+num2);

    /* Note 2: When receiving input we've always used the address of (&) operator to obtain the address of a variable.
     * Note we didn't do this for character arrays since they are pointers. scanf() second argument is then a pointer.
     *
     * When you have a pointer that contains an address you can use it directly as the second argument for scanf()
     */
    
    int value = 0; 
    int *pvalue = &value; 

    printf("Input an integer: \n"); 
    scanf("%d", pvalue); //pvalue is already a pointer variable, the there is no need to use the address of operator.  

    printf("You entered %d. \n", value);

    /* Note 3: Testing for NULL
     *  DO NOT dereference an uninitialized pointer!!!! - Might cause BIG problems!

     int * pt; 
     *pt = 5; //Where is 5 stored? No way to tell. Need to allocate the data first and then point to it. - Causes a segmentation fault.
              
     Always initialize to NULL if you don't intend to initialize the pointer. NULL is the pointer equivalent to 0 
     with ordinary numbers.        
     */

    int * somePointer = NULL; //Equivalent to int * somePointer = 0;
    if(!somePointer){
        printf("Pointer is null! Value is: %d", *somePointer);
    }
    return 0;
}
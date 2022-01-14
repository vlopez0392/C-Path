#include <stdio.h> 

int main(void){
    
    //Derefence operator * - You use it to access the value of the variable pointer by a pointer 
                        // - Compiler determines how the * operator is used depending on context.  
    int number = 15;
    int * pointer = &number; 

    int result = * pointer + 10; //Here we dereference the pointer and access its value; 
    printf("The result is %d \n", result);

    //Example 2 
    int count = 10, x;
    int * int_pointer = &count; 
    x = *int_pointer; 
    printf("count = %i, x = %i\n", count, x);
    
    //Displaying a pointer's value - use format specifier %p to display pointer address in hexadecimal form
    int otherNumber = 0;
    int * somePointer = NULL; //Good practice 

    otherNumber = 10;
    somePointer = &otherNumber;
    printf("somePointer value: %p \n",somePointer);
    printf("%lu", sizeof(somePointer));
    





    return 0;
}
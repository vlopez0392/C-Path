#include <stdio.h> 

int main(){
    //We can use the const keyword with a pointer to indicate that a value pointed to must not be changed.

    //Example 1: Pointer to constants 
    long value = 9999L; //This value can still change
    const long *pvalue = &value; 
    
    //Compiler will check for any statements that attempt to modify the value pointed by pvalue and flag such statements as error 
    
    //*pvalue = 8888L; //This is NOT legal.

    //This is legal 
    value = 7777L;

    //The pointer itself can also point to another value so this is legal. 
    long number = 8888L;
    pvalue = &number; //Still cannot use the dereference operator though. 



    //Example 2: Constant pointers 
    //In this case the address stored in a pointer cannot be changed. 

    int count = 43; 
    int *const pcount = &count; //Notice the syntax, ensures pointer always points to the same address. 

    //Then, this is illegal: 
    int anotherNumber = 5; 
    //pcount = &anothernumber;

    //In this case we can use the dereference operator to change the value of pcount;
    *pcount = 6;

    //Example 3:Constant pointer to constant value 
    //In this case, you cant change either the address of the pointer or dereference it to another value. 
    int item = 25; 
    const int *const pitem = &item;

    //Value of item can still change directly. This is legal: 
    item = 35; //Use const on item if you want ensure no changes at all.

    return 0;
}
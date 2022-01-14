#include <stdio.h>

int main(){
    //Example: Consider the following array 
    int values[100];
    values[0] = 100392; 
    values[1] = 271095;
    values[2] = 121791;

    //You can define a pointer called valuesPtr, which can be used to access
    //contained in the array 
    int *valuesPtr; //No need to designate pointer to array e.g. int[] *pointer 

    //What is the pointer pointing to? Note: values = pointer to array!
    valuesPtr = values; //No need for address of (&) operator either. 
    
    //First element in the array
    printf("The valuesPtr pointer is pointing to: %d: \n", *valuesPtr); 

    //We can use the address of operator (&) but we must specify the subscript 
    valuesPtr = &values[1];
    printf("The valuesPtr pointer is pointing to: %d: \n", *valuesPtr); 

    return 0;   
}

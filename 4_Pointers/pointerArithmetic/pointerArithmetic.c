#include <stdio.h>
//We can use pointers to sequence through the elements of an array. 
//Why? Each element in an array is just another address! 
int sumArray(int values[], const int sizeN){
    int sum = 0, *ptr;
    int * const arrayEnd = values + sizeN; 

    for(ptr = values; ptr < arrayEnd; ++ptr){
        sum += *ptr;
    }
    return sum;
}   
int main(void){
    //Example 1: Recall we can use the array name values to initialize the *valuesPtr
    int values[5];
    values[0] = 5;
    values[1] = 6;
    values[2] = 7;
    values[3] = 10;
    values[4] = 11;
    int *valuesPtr = values;

    //We access the first element of the array as follows: 
    printf("The first element of the array is: %d: \n", *valuesPtr);

    //The expression *(valuesPtr + i) can be used to access values[i]
    //This applies if and only if valuesPtr = values and not valuesPtr = &values[i] i != 0
    printf("The fourth element of the array is: %d: \n", *(valuesPtr+3));

    //Example 2: Summing the values in an array 
    int sumArray(int values[], const int sizeN);
    int sum = sumArray(values, 5); //To pass an array to a function simply specify the name of the array.
    printf("The sum of the array is: %d: \n ", sum);

    return 0;
}




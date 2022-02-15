#include <stdio.h>
void swapV(int, int);
void swapR(int *, int *);

int main(void){
    //Local variable definitions 
    int a = 100; 
    int b = 200; 

    //Calling swapV and printing the results 
    printf("Values of and b before swap by value: a = %d, b = %d \n", a,b);
    swapV(a,b);
    printf("Values of and b after swap by value: a = %d, b = %d \n", a,b);

    //Calling swapV and printing the results 
    printf("Values of and b before swap by refenrece: a = %d, b = %d \n", a,b);
    int * ar = &a;
    int * br = &b;
    swapR(ar,br);
    printf("Values of and b after swap by value: a = %d, b = %d \n", a,b);

    return 0;
}

//Function to swap values using pass by value
void swapV(int x, int y){
    int temp;
    temp = x;
    x = y; 
    y = temp;

    return;
}

//Function definition to swap the values using pass by reference 
void swapR(int * x, int * y){
    int temp;
    temp = *x;
    *x = *y; 
    *y = temp;

    return;
}
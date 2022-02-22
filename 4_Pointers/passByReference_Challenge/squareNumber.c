#include <stdio.h>

void squareNumber(float * num);

int main(void){
    float someNumber = 2.5;
    printf("Value of number before calling squareNumber: %.2f \n", someNumber);
    squareNumber(&someNumber);
    printf("Value of number after calling squareNumber: %.2f \n", someNumber);
    return 0;
}

void squareNumber(float * num){
    *num *= *num; 
    return;
}


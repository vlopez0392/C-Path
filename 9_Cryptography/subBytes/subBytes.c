#include <stdio.h> 
#include <stdlib.h>

int subBytes(char multInv); //char parameter is the multiplicative inverse in GF(2^8)
int byteToInt(int arr[], int arraySize);

int main(void){
    printf("Size of char in this system is %lu byte(s) \n", sizeof(char));
    int a = 0x30; 
    printf("Value of a is %x \n", a);
    a = (a & 0xF0) ^ ((a & 0x0F)<<4);
    printf("Value of a is %x \n", a);
    a = (a >>2);
    a = (a & 0xF0) ^ ((a & 0x0F)<<2);
    printf("Value of a is %x \n", a);
    subBytes(1);

    printf("\n");
    int binArr[8] = {1,1,1,1,0,0,1,0};
    byteToInt(binArr, sizeof(binArr));

    return 1;
}

int subBytes(char multInv){
    char affine1[8] = {0x8F, 0xC7, 0xE3, 0xF1, 0xF8, 0x7C, 0x3E, 0x1F};
    char affine2[8] = {1,0,0,0,1,1,1,0};
    printf("affine char array is: %s",affine2);
    int x = atoi(affine2);
    printf("affine char int equivalent is: %d", x);
    return 0;
}

int byteToInt(int binArr[], int arrSize){
    printf("size of int is: %lu", sizeof(int));
    int size = (int) arrSize/ binArr[0];
    printf("I was called ok \n");
    printf("array size is: %d", size);
    for(int i = size-1; i < 0; i--){
        printf("i = %d \n", binArr[i]);
    } 
    return 1;
}


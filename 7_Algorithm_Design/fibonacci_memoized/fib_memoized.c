#include <stdio.h>
#include <limits.h>

int fib_memoized(int n, int r[], int size_r);
void initialize_r(int *r, int size_r);
void printArr(int *r, int size_r);

int main(void){
    int n = 10; 
    int r[11] = {0};
    initialize_r(r,n+1);
    int res = fib_memoized(n+1, r, n+1);
    printf("Result is: %d", res);
    return 0;
}

void initialize_r(int *r, int size_r){
    *r = 0;
    *(r+1) = 1;
    for(int j = 2; j<size_r; j++){
        *(r+j) = INT_MIN;    
    }
}

void printArr(int *r, int size_r){
    for(int j = 0; j<size_r; j++){   
        printf("Value of j = %d, r[%d] = %d \n", j, j, *(r++));    
    }
}

int fib_memoized(int n, int r[], int size_r){
    if(r[n-1] != INT_MIN){
        return r[n-1];
    }else{
        r[n-1] = fib_memoized(n-1,r,size_r) + fib_memoized(n-2,r,size_r);
        return r[n-1];
    }
}
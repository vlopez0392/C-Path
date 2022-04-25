//Equivalent RISC-V assembly code 


#include <stdio.h>
int fib(int n);

int main(void){
    printf("The value of modified fibonacci with n = 5 is: %d", fib(5));
    return 1;
}

int fib(int n){
    if(n == 1){
        return 1;
    }else if (n == 0){
        return 0;
    }else{
        return fib(n-1) + 2*fib(n-2);
    }
}


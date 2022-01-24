#include <stdio.h> 
#include <stdlib.h> //for exit()

int main(void){
    int ch; 
    while((ch = getchar())!= EOF){
        putchar(ch);
    }
    return 0;
}


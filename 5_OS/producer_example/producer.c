#include <stdio.h>
#include <stdbool.h>

void producer(void){
    static char c = 'A';
    bool printing = 1;

    while(printing){
        if(c > 'Z'){
            printing = 0;
        }else{
            printf("%c", c);
            c++; 
        }
    }
}

int main(){
    producer();
    return 0;
}
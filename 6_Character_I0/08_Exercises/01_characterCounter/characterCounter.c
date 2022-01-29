/*
* characterCounter.c 
* This program counts the number of characters in its input until encountering EOF.
*/
#include <stdio.h>

int main(void){
    int counter = 0;
    char ch; 
    while((ch = getchar())!= EOF){
        if(ch == '\n'){
            continue;
        }
        printf("%c \n", ch);
        counter++;
    }
    printf("I counted %d characters", counter);
    return 0;
}
/*
* countUpperLower.c
* This program reads characters as an input stream and counts the number of uppercase and lowercase letters it encounters
* until EOF is reached.
*/
#include <stdio.h>

int main(void){
    char ch;
    int lower= 0 , upper=0;

    while((ch = getchar()) != EOF){
        if(ch >= 65 && ch <=90){
            upper++;
        }else if(ch >= 97 & ch <=122){
            lower++;
        }
    }
    printf("I have found %d uppercase characters and %d lower case characters", upper, lower);

    return 0;
}
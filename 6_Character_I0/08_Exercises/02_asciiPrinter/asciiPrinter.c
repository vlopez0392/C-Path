/*
* asciiPrinter.c                                                                                    *
* This program reads input as a stream of characters until encountering EOF and                     *
* prints each input character and its ASCII decimal value as pairs. 10 pairs per line are printed   *
* unless a new-line character is encountered. Non-printable characters are skipped.                                                          *
*/
#include <stdio.h>
#include <string.h>
#define PAIRLIMIT 10

int main(void){
    char ch; 
    int asciiValue, counter = 0, lineNumber = 0;    

    while((ch = getchar())!= EOF){
        asciiValue = (int)ch;           
        if(counter == 0){
            printf("Line# %d: ", lineNumber);
            lineNumber++;
        } 

        if(counter < (PAIRLIMIT-1)){
            if(ch == '\n'){
                printf(" | \\n, %d |\n", asciiValue);
                counter = 0;
                continue;
            }               
            counter++;
            printf(" | %c, %d | ", ch, asciiValue);
        }else{
            printf(" | %c, %d | ", ch, asciiValue);
            printf("\n");
            counter = 0;
        }
    }
    return 0;
}
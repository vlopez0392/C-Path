/*
* wordLetterAverage.c                                            *
* This program computes the average number of letters per word.  *
* Program execution halts when the EOF is encountered            *
*/
#include <stdio.h>
#define SPACE 32    //Space

int isPunctiation(char c);
int isLetter(char c);

int main(void){
    char ch; 
    int words = 0, letters = 0, firstLetter = 1;
    float average; //Average is defined as the total number of letters / total number of words
    
    while((ch = getchar())!= EOF){
        if(isLetter(ch)){
            if(firstLetter){
                firstLetter = 0;
                words++;
            }
            letters++;
        }else{
            if(ch == SPACE){ 
                ch = getchar(); //Look-ahead once if a space is found.
                if(isLetter(ch)){ 
                    if(firstLetter){
                        firstLetter = 0;
                    }
                    letters++;
                    words++;
                }
            }else if(ch == '\n'){ //Handle the new line
                firstLetter = 1;
                continue;
            }
        }   
    }
    printf("I found %d letters and %d words \n", letters, words);
    average = (float)letters/words;
    printf("The average number of letters per word in the input is: %d/%d = %.2f letters per word. ", letters,words,average);
    return 0;
}

int isPunctiation(char c){
    if(c>= 33 && c<=64){
        return 1;
    }

    if(c>=91 && c<=96){
        return 1;
    }

    if(c>=123 && c<=127){
        return 1;
    }
    return 0;
}

int isLetter(char c){
    if((c >= 65 && c <=90) || (c >= 97 && c <=122)){
        return 1;
    }
    return 0;
}
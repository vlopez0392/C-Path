#include <stdio.h>
#include <string.h>

int main(void){ 
    //Declaring a string in C 
    char myString[6]; //Can accomodate up to 7 characters, need to include the null terminator.

    //Initializing a string when it is declared:
    char word[6] = {"HELLO"};
    char * pWord = word; 
    char nullTerminator = '1';

    while(*pWord){
        printf("Current character: %c, Address: %p \n", *pWord, pWord); 
        pWord++;
    }
    //Check if pWord points to the null terminator
    if(!(*pWord)){
        nullTerminator = '0';
        printf("pWord now points to: %p and its value is %c\n", pWord, nullTerminator);
    }

    //Initializing an already declared char array with strcpy
    printf("word: %s \n",word);
    printf("size of word: %lu \n",sizeof(word));
    strcpy(myString, word);
    printf("myString: %s, word: %s \n", myString, word);
    printf("myString size: %lu, word size: %lu \n", sizeof(myString), sizeof(word));
}
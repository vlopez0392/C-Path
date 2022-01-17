#include <stdio.h>
#include <stdlib.h> //for exit()

//Opens a file and displays it in the screen as output
int main(){
    int ch; 
    FILE * fp; 
    char fname[50];
    
    printf("Enter the name of the file: ");
    scanf("%s", fname);
    fp = fopen(fname, "r"); //Open the file

    if(fp == NULL){
        printf("Failed to open a file! Please try again");
        exit(1); //Quits program
    }

    //getc(fp) - Gets a character from an open file 
    while((ch = getc(fp))!= EOF){
        putchar(ch);
    }
    fclose(fp); //Close the file

    return 0; 
}
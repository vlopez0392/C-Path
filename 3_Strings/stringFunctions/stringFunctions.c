#include <stdio.h>
#include <string.h>

int main(){

    //String copy
    char myString[] = "My name is Jason";
    char temp[50];

    strncpy(temp, myString, sizeof(temp)-1); //First parameter is destination, second parameter is string source
                                             //Third parameter is the maximum number fo characters to copy
    printf("temp now holds the value of: %s \n", temp);

    //String Concatenation
    char src[50], dest[50];

    strcpy(src, "This is source");
    strcpy(dest, "This is destination");

    strncat(dest, src, 15);
    printf("Final destination string: |%s|: " ,dest);

    //String comparison - Compares string contents
    


    return 0;
}
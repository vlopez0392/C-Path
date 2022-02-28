#include <stdio.h>
#include <string.h>

int main(){
    char myString[] = "My name is Vick";
    
    //String length 
    printf("The length of this string is: %lu \n", strlen(myString));

    //String copy
    //////strncpy() 
    char temp[50];
    strncpy(temp, myString, sizeof(temp)-1); //First parameter is destination, second parameter is string source
                                             //Third parameter is the maximum number fo characters to copy
    printf("temp now holds the value of: %s \n", temp);
    
    /////strcpy()
    char src[50], dest[50];
    strcpy(src, " This is source, This is source");
    strcpy(dest, "This is destination");
   
    //String Concatenation
    ////Example 1
    strncat(dest, src, 10);
    printf("Final destination string: |%s|: ",dest);

    ////Example 2
    char anotherString[] = " my string"; 
    char input[80]; 

    printf("\nEnter a string to be concatenated: ");
    scanf("%s", input); 

    printf("\nThe string %s to be concatenated with %s is: ", anotherString, input);
    printf("%s", strcat(input, anotherString));

    //String comparison - Compares string contents

    return 0;
}
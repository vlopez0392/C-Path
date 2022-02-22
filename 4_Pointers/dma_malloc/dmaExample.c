#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *str = NULL; 

    //Initial memory allocation 
    str = (char *)malloc(15*sizeof(char));
    strcpy(str, "jason"); 
    printf("String = %s, address = %p\n", str, str);

    //Reallocation memory
    str = (char *)realloc(str, 25*sizeof(char));
    strcat(str, ".com"); 
    printf("String = %s, address = %p\n", str, str);

    //Free the memory 
    free(str);
    return 0;
}
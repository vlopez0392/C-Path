#include <stdio.h>

//Consider the following functions in both array and pointer
void copyStringArray(char to[], char from[]){
    int i;
    for(i = 0 ; from[i]!='\0'; ++i){
        to[i] = from[i];
    }
    to[i] = '\0';
}

void copyStringPtr(char *to, char *from){
    for(; *from!='\0'; from++, to++){
        *to = *from;
    }
    *to = '\n';
}

int main(void){
    //Common pointer application: Using a pointer to an character string array
    char string1[] = "Vick is cool";
    char string2[30]; 

    copyStringPtr(string2, string1);
    printf("String 1 and String 2 are: %s, %s", string1, string2);

    return 0;
}
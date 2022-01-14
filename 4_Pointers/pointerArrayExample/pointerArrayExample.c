#include <stdio.h>
#include <string.h>

int main(void){
    //This program demonstrates the effect of adding an integer value to a pointer.
    char multiple[] = "a string";
    char *p = multiple;

    for(int i = 0; i<strnlen(multiple, sizeof(multiple)); ++i){
        printf("%d multiple[%d] = %c &multiple[%d] = %p |  %d *(p+%d)=%c p+%d= %p \n", i, i, multiple[i], i, &multiple[i], i, i, *(p+i),i,p+i);
    }

    return 0;
}
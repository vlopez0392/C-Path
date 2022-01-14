#include <stdio.h>

int main(){
    //A pointer of type void* can contain the address of a data item of any type.
    //Allows flexibility, but an explicit cast is necessary to dereference a void* pointer.

    //Example 
    int i =0;
    float f = 2.34f; 
    char ch = 'k';
    void *vptr; 

    vptr = &i;
    printf("The value of i = %d\n", *(int *)vptr); //Dereferencing an explicit pointer.
    
    vptr = &f;
    printf("The value of f = %f\n", *(float *)vptr);

    vptr = &ch;
    printf("The value of ch = %c\n", *(char *)vptr);
    return 0;
}
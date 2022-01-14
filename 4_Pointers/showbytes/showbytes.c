 #include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    for(int i = 0; i<len; i++){
        printf(" %.2x", start[i]);
    }  
    printf("\n"); 
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}

int main(void){
    int i = 5;
    show_int(i);
 }
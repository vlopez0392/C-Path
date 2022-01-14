#include <stdio.h>
#include <string.h> 
#define DENSITY 2.64 //Human density in lbs per cubic feet

int main(){
    float weight, volume;
    int size, letters;
    char name[40]; 

    printf("Hi!, What's your first name? \n");
    scanf("%s", name); 
    printf("%s, What is your weight in pounds? \n", name);
    scanf("%f", &weight);
    size = sizeof name;
    letters = strlen(name);
    volume = weight / DENSITY;

    //Output to console 
    printf("Well, %s your volume is %2.2f cubic feet \n", name, volume);
    printf("Also, your first name has %d letters, \n", letters);
    printf("And we have %d bytes to store it. \n", size);
}
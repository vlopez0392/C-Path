/*Version 3: Improved version, handles the newline after the user guess 
and only accepts y/n as a response*/
#include <stdio.h>

int main(void){
    int guess = 1; 
    char response; 

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it. \nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong. \n");

    printf("Uh... is your number %d?\n",guess);
    
    while((response = getchar()) != 'y'){
        if(response == 'n'){
            printf("Well, then, is it %d?\n", ++guess);
        }else{
            printf("Sorry, I only understand only y or n. \n");
        }

        while(getchar() != '\n'){
            continue; //Skip rest of input line
        }
    }
    printf("I knew I could do it! \n");
    return 0;
}
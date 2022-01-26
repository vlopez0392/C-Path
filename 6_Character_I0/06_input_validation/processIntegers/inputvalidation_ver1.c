/*Input validation Ver 1
* This program simply prints non-negative numbers. Its main purpose is to
* handle user input errors with grace.
*
* Comments: If the user inputs something other than a number, the program lets the user try again.
*/
#include <stdio.h>
int main(void){
    long n = 1; 
    char ch;
    while(n>=0){  //Detect an out-of-range value 
        printf("Enter a number or press q to quit: ");
        if(scanf("%ld", &n) == 1){
            printf("You have input: %ld \n", n);
            continue;
        }else if((ch = getchar())== 'q'){
            if(getchar() != '\n'){
                while(getchar()!= '\n');
                printf("I only understand q to quit, please try again \n");
                continue;
            }
            printf("Terminating program, bye!");
            break;
        }else{
            putchar(ch);
            while((ch = getchar()) != '\n'){
                putchar(ch);
            }
            printf(" is not a number Please try again \n");
        }
    }
    return 0;
}


/*Input validation Ver 1
* This program simply prints non-negative numbers. Its main purpose is to
* handle user input errors with grace.
*/
#include <stdio.h>
int main(void){
    long n; 
    scanf("%ld", &n);  //Get first value
    while(n>=0){       //Detect an out-of-range value 
        printf("Enter a number: ");
        printf("You input the following number %ld \n", n);
        scanf("%ld", &n);
    }
    return 0;
}


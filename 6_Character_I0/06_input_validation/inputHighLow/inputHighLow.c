//inputHighLow.c - Returns the sum of squares of two integers. Input is validated.

#include <stdio.h>
#include <stdbool.h>

long get_long(void);
bool bad_limits(long begin, long end, long low, long high);
double sum_squares(long a, long b);

int main(void){
    const long MIN = -1000000L;
    const long MAX =  1000000L;
    long start, stop;
    double answer;

    printf("This program computes the sum of squares only if the numbers are in the range [%ld, %ld] \n"
    "Enter the limits (enter 0 for both limits to quit): \n"
    "Enter lower limit: ", MIN,MAX);

    start = get_long();
    printf("Enter upper limit: ");
    stop = get_long();
    while(start != 0 || stop!=0){
        if(bad_limits(start, stop, MIN, MAX)){
            printf("Please try again. \n");
        }else{
            answer = sum_squares(start, stop);
            printf("The  sum of the squares of the integers ");
            printf(" in the range [%ld, %ld] is %g \n", start, stop, answer);
        }

        printf("Enter the limits (enter 0 for both limits to quit): \n"
        "Lower limit: ");
        start = get_long();
        printf("Enter upper limit: ");
        stop = get_long();
    }
    printf("Done! \n");
    return 0;
}

long get_long(void){
    long input;
    char ch;

    while(scanf("%ld", &input)!=1){
        while((ch = getchar())!= '\n'){
            putchar(ch); //Dispose of bad input
        }
        printf(" is not an integer. Please enter an integer value such as -128, 3, 25 ");
    }

    return input;
}

double sum_squares(long a, long b){
    return (double)(a*a + b*b);
}

bool bad_limits(long begin, long end, long low, long high){
    bool not_good = false; 

    if(begin>end){
        printf("%ld musn't be smaller than %ld. \n", begin, end);
        not_good = true;
    }

    if(begin < low || end < low){
        printf("Values must be %ld or greater. \n", low);
        not_good = true;
    }

    if(begin > high || end > high){
        printf("Values must be %ld or less \n", high);
        not_good = true;
    }

    return not_good;
}

#include <stdio.h> 
#include <limits.h>

/*You have n coins with certain values. Your task is to find all money sums you can create using these coins.

    Input
    The first input line has an integer n: the number of coins.
    The next line has n integers x1,x2,…,xn: the values of the coins.

    Output
    First print an integer k: the number of distinct money sums. After this, print all possible sums in increasing order.
*/ 

int countSums(int coinValue[], int startCoin, int coins, int maxSum);
int getMaxSum(int arr[], int arrSize);

int main(void){
    //Input example
    int n = 4;
    int coins[4] = {4,2,5,2};

    int maxSum = getMaxSum(coins, n);
    printf("Max sum is: %d ", maxSum);

    int moneySums = countSums(coins, 0, n, maxSum);
    printf("Possible money sums is: %d ", moneySums);
    return 0;
}

int countSums(int coinValue[], int startCoin, int coins, int maxSum){
    
    if(startCoin == coins || maxSum  < 0)
    {
        return 0;
    }
    int countSumsExc = 1 + countSums(coinValue, startCoin+1, coins, maxSum);
    int countSumsInc = 1 + countSums(coinValue, startCoin+1, coins, maxSum-coinValue[startCoin+1]);

    return countSumsInc+countSumsExc;
}   

int getMaxSum(int arr[], int arrSize){
    
    int maxSum = 0;
    for(int i =0 ; i < arrSize; i++){
       maxSum += arr[i];
    }
    return maxSum;
}

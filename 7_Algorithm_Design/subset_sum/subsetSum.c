#include <stdio.h>
#include <limits.h>

/*Given a set if positive integers and an integer k, check if there is any non-empty
  subset that sums to k

  Input A = {7,3,2,5,8}
  k = 14

  Output: Subset with given sum exists 
*/
int subsetSumExists(int arr[],int startIdx, int sum);

int main(void){
    int arr[5] = {7,3,2,5,8};
    int sum = 14; 
    int startIdx = 5;
    int exists = subsetSumExists(arr, startIdx, sum);
    printf("Subset sum exists: %d", exists);
    return 0;
}

//First call should be with startIdx = n, int sum = k
int subsetSumExists(int arr[], int startIdx, int sum){
    //Base cases
    //Combination exceeds sum or ran out of elements
    if(sum < 0 || startIdx < 0){ 
        return 0;

    //Subset sums exactly to k
    }else if (sum == 0){
        return 1;
    }

    int include = subsetSumExists(arr, startIdx-1, sum - arr[startIdx -1]);
    int exclude = subsetSumExists(arr, startIdx-1, sum);
    
    return include || exclude ;
}
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
    int length = (int) sizeof(arr)/sizeof(arr[0]);
    int sum = 10; 
    int startIdx = length - 1;

    int exists = subsetSumExists(arr, startIdx, sum);
    if(exists){
        printf("Subset sum exists");
    }else{
        printf("Subset sum does not exist");
    }
    return 0;
}

//First call should be with startIdx = n, int sum = k
int subsetSumExists(int arr[], int startIdx, int sum){
    //Base cases
    //Subset sums exactly to k
    if (sum == 0){
        return 1;
    }
    //Combination exceeds sum or ran out of elements
    if(sum < 0 || startIdx < 0){ 
        return 0;
    }

    //Include or exclude the jth Element
    int include = subsetSumExists(arr, startIdx-1, sum - arr[startIdx]);
    int exclude = subsetSumExists(arr, startIdx-1, sum);

    return include || exclude;
}
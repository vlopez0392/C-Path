#include <stdio.h> 
#include <limits.h>
/*
    Given a goldmine called M of (n x m) dimensions. Each field in this mine contains 
    a positive integer which is the amount of gold in tons. Initially the miner can start
    from any row in the first column. From a given cell, the miner can move: 

    1. To the cell diagonally up towards the right 
    2. To the right 
    3. To the cell diagonally down towards the right 

    Find out the maximum amount of gold of which he can collect.

    Input: n = 3, m = 3 
    M = {{1,3,3},
         {2,1,4}
         {0,6,4}
    Output = 12; 

    Path: (1,0)->(2,1)->(2,2)
*/

int max(int a, int b, int c);
int maxGold(int M[4][4], int i, int j, int n, int m);
void printOPT(int OPT[], int size);

int main(void){ 
    // //Case 1
    // int M[3][3] = {{1,3,3},
    //                {2,1,4},
    //                {0,6,4}};
    // int n = 3, m = 3;

    // //Optimal paths from each starting point for case 1
    // int OPT1[n]; 
    // for(int i = 0; i < n ; i++){
    //     OPT1[i] = maxGold(M, i, 0, n, m);
    // }
    // printOPT(OPT1, n);

    //Case 2 
    int N[4][4] = {{1, 3, 1, 5},
                   {2, 2, 4, 1},
                   {5, 0, 2, 3},
                   {0, 6, 1, 2}};
    int n = 4, m = 4;

    //Optimal paths from each starting point for case 1
    int OPT2[n]; 
    for(int i = 0; i < n ; i++){
        OPT2[i] = maxGold(N, i, 0, n, m);
    }
    printOPT(OPT2, n);
    return 0;
}

int maxGold(int M[4][4], int i, int j, int n, int m){
    //Base cases: Take impossible paths or reach the last column
    if(i < 0 || i == n || j==m){
        return 0;
    }
    int maxgold = M[i][j] + max(maxGold(M,i+1, j+1,n,m), maxGold(M, i, j+1, n, m), maxGold(M, i-1, j+1, n,m)); 
    return maxgold;
}

int max(int a, int b, int c){
    if(a>=b && a>=c){
        return a;
    }else if(b>=a && b>=c){
        return b;
    }
    return c;
}

void printOPT(int OPT[], int size){
    for(int i = 0; i < size ; i++){
        printf("Optimal gold collected from starting point (%d, %d) = %d \n", i,0,OPT[i]);
    }
}
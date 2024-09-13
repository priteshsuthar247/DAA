#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int dp[100][100];

int matrixChainMemoised(int p[], int i, int j) 
{
    if (i == j) 
    {
        return 0;
    }
    if (dp[i][j] != -1) 
    {
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for (int k = i; k < j; k++) 
    {
        int cost = matrixChainMemoised(p, i, k) + matrixChainMemoised(p, k + 1, j) + p[i - 1] * p[k] * p[j];
        if (cost < dp[i][j]) {
            dp[i][j] = cost;
        }
    }
    return dp[i][j];
}

int MatrixChainOrder(int p[], int n) 
{
    return matrixChainMemoised(p, 1, n - 1);
}

int main() 
{
    srand(time(NULL));

    int n = 5;
    int arr[n];
    
    int upper_bound = 10;
    int lower_bound = 1;

    for (int i = 0; i < n; i++) 
    {
        arr[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    }

    for (int i = 0; i < 100; i++) 
    {
        for (int j = 0; j < 100; j++) 
        {
            dp[i][j] = -1;
        }
    }

    printf("Matrix dimensions: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, n));
    printf("\n");
    system("PAUSE");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int max(int a, int b) 
{ 
    return (a > b) ? a : b; 
}

int knapsack(int W, int wt[], int val[], int n) 
{
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() 
{
    int n = 5;
    int W = 1000;

    int weight[n];
    int profit[n];

    srand(time(NULL));
    int upper_bound = 1000;
    int lower_bound = 100;

    printf("Weights: ");
    for (int i = 0; i < n; i++) 
    {
        weight[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
        printf("%d ", weight[i]);
    }
    printf("\n");

    printf("Profits: ");
    for (int i = 0; i < n; i++) 
    {
        profit[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
        printf("%d ", profit[i]);
    }
    printf("\n");

    printf("Maximum profit: %d\n", knapsack(W, weight, profit, n));

    printf("\n");
    system("PAUSE");
    return 0;
}
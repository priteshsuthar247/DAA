#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    int n = 5;
    int weight[n], profit[n], ratio[n], Totalvalue = 0, temp, capacity = 10;
    int i, j;
    int upper_bound = 100;
    int lower_bound = 0;

    srand(time(0)); // Seed for random number generation

    printf("Weights: ");
    for (i = 0; i < n; i++) 
    {
        weight[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
        printf("%d, ", weight[i]);
    }
    printf("\nProfits: ");
    for (i = 0; i < n; i++) 
    {
        profit[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
        printf("%d, ", profit[i]);
    }
    printf("\n");

    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (ratio[i] < ratio[j]) 
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    printf("\n");
    printf("Knapsack problems using Greedy Algorithm:");
    for (i = 0; i < n; i++) 
    {
        if (weight[i] > capacity)
            break;
        else 
        {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
    }

    if (i < n)
        Totalvalue += (ratio[i] * capacity);

    printf("\nThe maximum value is: %d\n", Totalvalue);
    system("PAUSE");
    return 0;
}

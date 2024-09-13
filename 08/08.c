#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SUM 100

int coins[MAX_SUM];
int sum = 9;
int numberofCoins;

void initdynamicprogTable(int dynamicprogTable[][MAX_SUM+1]) {
    for (int i = 0; i <= sum; i++) {
        dynamicprogTable[0][i] = 0;
    }
    for (int i = 0; i <= numberofCoins; i++) {
        dynamicprogTable[i][0] = 1;
    }
}

int solution(int dynamicprogTable[][MAX_SUM+1]) {
    for (int coinindex = 1; coinindex <= numberofCoins; coinindex++) {
        for (int dynamicprogSum = 1; dynamicprogSum <= sum; dynamicprogSum++) {
            if (coins[coinindex-1] > dynamicprogSum) {
                dynamicprogTable[coinindex][dynamicprogSum] = dynamicprogTable[coinindex-1][dynamicprogSum];
            } else {
                dynamicprogTable[coinindex][dynamicprogSum] = dynamicprogTable[coinindex-1][dynamicprogSum] 
                    + dynamicprogTable[coinindex][dynamicprogSum - coins[coinindex-1]];
            }
        }
    }
    return dynamicprogTable[numberofCoins][sum];
}

int main() {
    srand(time(NULL));

    int n = 5;
    int upper_bound = 10;
    int lower_bound = 1;

    numberofCoins = n;

    for (int i = 0; i < n; i++) {
        coins[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    }

    int dynamicprogTable[numberofCoins + 1][MAX_SUM + 1];
    initdynamicprogTable(dynamicprogTable);

    printf("Sum: %d\n", sum);

    printf("Coins: ");
    for (int i = 0; i < numberofCoins; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n");

    printf("Total Solutions: %d\n", solution(dynamicprogTable));

    printf("\n");
    system("PAUSE");
    return 0;
}
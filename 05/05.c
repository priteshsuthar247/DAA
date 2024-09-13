#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int f1(int a) 
{
    if (a >= 1)
        return a * f1(a - 1);
    else
        return 1;
}

int main() 
{
    int n;
    srand(time(NULL));
    int upper_bound = 50;
    int lower_bound = 1;
    n = rand() % (upper_bound - lower_bound + 1) + lower_bound;
    printf("Generated number: %d\n", n);
    printf("Factorial of %d = %lld\n", n, f1(n));
    printf("\n");
    system("PAUSE");
    return 0;
}

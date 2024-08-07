#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n = 5;
    int array[n], key,j;
    srand(time(NULL));
    int upper_bound = 1000;
    int lower_bound = 100;
    printf("Unsorted Array: ");
    for (int i = 0; i < n; i++) 
    {
        array[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
        printf("%d, ", array[i]);
    }
    printf("\n");
    for (int i = 1; i < n; i++)
    {
        key=array[i];
        j = i - 1;
        while (j>=0 && array[j]>key)
        {
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=key;
    }
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ",array[i]);
    }
    printf("\n");
    system("PAUSE");
    return 0;
}
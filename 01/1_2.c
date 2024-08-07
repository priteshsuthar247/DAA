#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n=5,array[n],temp=0,min;
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
    for (int i = 0; i < n-1; i++)
    {
        min=i;
        for (int j = i+1; j < n; j++)
        {
            if (array[j]<array[min])
            {
                min=j;
            }
        }
        if (min!=i)
        {
            temp=array[min];
            array[min]=array[i];
            array[i]=temp;
        }
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
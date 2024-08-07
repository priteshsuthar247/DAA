#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n=10,array[n],swap=0,temp=0;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (array[i]>array[j])
            {
                temp=array[i];
                array[i]=array[j];
                array[j]=temp;
                swap++;
            }
        }
    }
    if (swap==0)
    {
        printf("Array is already sorted.\n");
    }
    else
    {
        printf("Sorted Array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d, ",array[i]);
        }
    }
    printf("\n");
    system("PAUSE");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge(int marr[], int mid, int low, int high)
{
    int i, j, k, temp[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (marr[i] < marr[j])
        {
            temp[k] = marr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = marr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = marr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = marr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        marr[i] = temp[i];
    }
}
void msort(int marr[], int low, int high)
{
    int mid; 
    if(low<high)
    {
        mid = (low + high) /2;
        msort(marr, low, mid);
        msort(marr, mid+1, high);
        merge(marr, mid, low, high);
    }
}
int main()
{
    int n = 5;
    int array[n],low=0,high=n-1;
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
    msort(array,low,high);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ",array[i]);
    }
    printf("\n");
    system("PAUSE");
    return 0;
}
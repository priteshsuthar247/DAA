#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int partition(int qarr[], int low, int high)
{
    int pivot = qarr[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (qarr[i] <= pivot)
        {
            i++;
        }

        while (qarr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = qarr[i];
            qarr[i] = qarr[j];
            qarr[j] = temp;
        }
    } while (i < j);

    temp = qarr[low];
    qarr[low] = qarr[j];
    qarr[j] = temp;
    return j;
}
void qusort(int qarr[], int low, int high)
{
    int partitionIndex;
    if (low < high)
    {
        partitionIndex = partition(qarr, low, high); 
        qusort(qarr, low, partitionIndex - 1);
        qusort(qarr, partitionIndex + 1, high);
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
    qusort(array,low,high);
    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ",array[i]);
    }
    printf("\n");
    system("PAUSE");
    return 0;
}
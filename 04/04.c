#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i) 
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest]) 
    {
        largest = left;
    }
    if (right < N && arr[right] > arr[largest]) 
    {
        largest = right;
    }
    if (largest != i) 
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N) 
{
    for (int i = N / 2 - 1; i >= 0; i--) 
    {
        heapify(arr, N, i);
    }
    for (int i = N - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main() 
{
    int n = 10;
    int array[n];

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

    int N = sizeof(array) / sizeof(array[0]);
    heapSort(array, N);

    printf("Sorted Array: ");
    for (int i = 0; i < N; i++) 
    {
        printf("%d, ", array[i]);
    }
    printf("\n");
    system("PAUSE");
    return 0;
}

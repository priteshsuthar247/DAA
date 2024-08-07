#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n=5,search,flag=0,array[n];
    srand(time(NULL));
    int upper_bound = 1000;
    int lower_bound = 100;
    for (int i = 0; i < n; i++) 
    {
        array[i] = rand() % (upper_bound - lower_bound + 1) + lower_bound;
        printf("%d, ", array[i]);
    }
    printf("\n");
    printf("Search: ");
    scanf("%d", &search);
    for (int i = 0; i < n; i++)
    {
        if (array[i]==search)
        {
            printf("Found %d at %d index.\n", search,i);
            flag=1;
        }
    }
    if (flag==0)
    {
        printf("%d is not present in the array\n", search);
    }
    
    system("PAUSE");
    return 0;
}
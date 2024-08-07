#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int n=5,array[n],search,flag=0,high=4,low=0,temp=0,mid;
    srand(time(NULL));
    int upper_bound = 1000;
    int lower_bound = 100;
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
            }
        }
    }
    printf("Search: ");
    scanf("%d",&search);
    while (low<=high)
    {
        mid=(high+low)/2;
        if (array[mid]==search)
        {
            printf("Found %d\n",search);
            flag = 1;
        }
        else if (array[mid]<search)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if (flag==0)
    {
        printf("%d is not present in the array\n", search);
    }
    
    system("PAUSE");
    return 0;
}
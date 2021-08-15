#include<stdio.h>
#include<stdlib.h>

void countSort(int a[],int n)
{
    int max=0 ;
    for (int i = 0; i < n; i++)
    {
        if(a[i] > max)
            max = a[i];
    }


    int sorted[max+1];
    for (int i = 0; i <= max; i++)
        sorted[i] = 0;
    
    
    for(int i=0;i<n;i++)
    {
        int ele = a[i];
        sorted[ele]++;
    }

    int j=0;
    int element;
    for (int i = 0; i <= max; i++)
    {
        if(sorted[i]!=0)
        {
            element = sorted[i];
            while (element)
            {
                a[j] = i;
                element--;
                j++;
            }
            
        }
    }    
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    // int a[] = {8, 10, 7, 1, 3};
    int a[] = {100, 99, 98, 97, 96, 95, 94, 94};
    int n = sizeof(a) / sizeof(int);

    printf("Before Sorting: ");
    printArray(a, n);
    countSort(a,n);
    printf("\nAfter Sorting: ");
    printArray(a, n);
    return 0;
}
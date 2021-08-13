#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[],int n)
{
    int key,j=0;
    for (int i = 1; i <= n-1; i++)
    {
        key = a[i];
        j = i-1;

        while (a[j]>key && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;       
    }
}


void printArray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int a[] = {10,30,20,100,90};
    int n = sizeof(a)/sizeof(int);
    printf("Before Sorting: ");
    printArray(a,n);
    insertionSort(a,n);
    printf("\nAfter Sorting: ");
    printArray(a,n);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int a[],int n){
    int temp = 0;
    int isSorted = 0;
    for(int i=0;i<n-1;i++)
    {
        isSorted = 1;
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                isSorted=0;
            }
        }

        //If array is already sorted or it's sorted in one pass just close the function.
        if(isSorted)
            return;
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
    bubbleSort(a,n);
    printf("\nAfter Sorting: ");
    printArray(a,n);
    return 0;
}
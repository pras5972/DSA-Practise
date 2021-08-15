#include <stdio.h>
#include <stdlib.h>

int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int temp = 0;
    int i = low + 1;
    int j = high;

    do
    {
        while (a[i] <= pivot)
            i++;
        
        while (a[j] > pivot)
            j--;

        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}
void quickSort(int a[], int low, int high)
{
    int partitionIndex;

    if (low < high)
    {
        partitionIndex = partition(a, low, high);
        quickSort(a, low, partitionIndex - 1);
        quickSort(a, partitionIndex + 1, high);
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
    // int n=8;

    printf("Before Sorting: ");
    printArray(a, n);
    quickSort(a, 0, n-1);
    printf("\nAfter Sorting: ");
    printArray(a, n);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void selectionSort(int a[], int n)
{
    int min = INT_MAX;
    int min_index = 0;
    int temp = 0;
    int low = 0;
    while (low < n)
    {
        for (int i = low; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
                min_index = i;
            }
        }

        temp = a[low];
        a[low] = a[min_index];
        a[min_index] = temp;

        low++;
        min = INT_MAX;
    }
    // printf("minimum element is %d and found at %d",min,min_index);
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
    int a[] = {100, 99, 98, 97, 96, 95, 94,94};
    int n = sizeof(a) / sizeof(int);

    printf("Before Sorting: ");
    printArray(a, n);
    selectionSort(a, n);
    printf("\nAfter Sorting: ");
    printArray(a, n);
    return 0;
}
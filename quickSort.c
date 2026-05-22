#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Partition Function
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low + 1;
    int j = high;
    int temp;

    while(1)
    {
        while(i <= high && a[i] <= pivot)
            i++;

        while(a[j] > pivot)
            j--;

        if(i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
            break;
    }

    temp = a[low];
    a[low] = a[j];
    a[j] = temp;

    return j;
}

// Quick Sort Function
void quickSort(int a[], int low, int high)
{
    if(low < high)
    {
        int k = partition(a, low, high);

        quickSort(a, low, k - 1);
        quickSort(a, k + 1, high);
    }
}

int main()
{
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    // Generate random numbers
    srand(time(0));

    for(i = 0; i < n; i++)
        a[i] = rand() % 10000;

    // Start time
    clock_t start = clock();

    quickSort(a, 0, n - 1);

    // End time
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Display sorted array
    printf("\nSorted Array:\n");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n\nTime Complexity: O(n log n)");
    printf("\nExecution Time: %f seconds\n", time_taken);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100000

// Merge Function
void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[MAX];

    while(i <= mid && j <= high)
    {
        if(a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
        temp[k++] = a[i++];

    while(j <= high)
        temp[k++] = a[j++];

    for(i = low; i <= high; i++)
        a[i] = temp[i];
}

// Merge Sort Function
void mergeSort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main()
{
    int a[MAX], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Generate random numbers
    srand(time(0));

    for(i = 0; i < n; i++)
        a[i] = rand() % 10000;

    // Start time
    clock_t start = clock();

    mergeSort(a, 0, n - 1);

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
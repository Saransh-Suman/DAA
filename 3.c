// Design and implement C/C++ Program to sort a given set of n integer elements using Quick Sort
// method and compute its time complexity. Run the program for varied values of n> 5000 and record
// the time taken to sort. Plot a graph of the time taken versus n. The elements can be read from a file
// or can be generated using the random number generator.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int temp;
    int j = high + 1;
    while (i <= j)
    {
        do
            i++;
        while (arr[i] <= pivot);
        do
            j--;
        while (arr[j] > pivot);

        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}

void quickSort(int arr[], int low, int high)
{
    int k;
    if (low < high)
    {
        k = partition(arr, low, high);
        quickSort(arr, low, k - 1);
        quickSort(arr, k + 1, high);
    }
}

int main()
{
    srand(time(0)); // Seed for random number generation
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    // printf("Randomly generated array:\n");
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 1000; // Generating random numbers between 0 and 999
        // printf("%d ", a[i]);
    }
    a[n] = 9999;
    clock_t start = clock();
    quickSort(a, 0, n - 1);
    clock_t end = clock();
    // printf("\n Sorted array:\n");
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    printf("\n");
    printf("Total time taken to start %d elements is %f \n ", n, ((double)(end - start) / CLOCKS_PER_SEC));
    return 0;
}
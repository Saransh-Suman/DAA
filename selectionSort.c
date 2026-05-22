#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Selection Sort Function
void selectionSort(int a[], int n)
{
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++)
    {
        min = i;

        for(j = i + 1; j < n; j++)
        {
            if(a[j] < a[min])
                min = j;
        }

        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
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
    {
        a[i] = rand() % 10000;
    }

    // Start time
    clock_t start = clock();

    selectionSort(a, n);

    // End time
    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    // Display sorted array
    // printf("\nSorted Array:\n");
    // for(i = 0; i < n; i++)
    // {
    //     printf("%d ", a[i]);
    // }

    // Time Complexity
    printf("\n\nTime Complexity: O(n^2)");
    printf("\nExecution Time: %f seconds\n", time_taken);

    return 0;
}
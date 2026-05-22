#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// // Selection Sort Function
// void selectionSort(int a[], int n)
// {
//     int i, j, min, temp;

//     for(i = 0; i < n - 1; i++)
//     {
//         min = i;

//         for(j = i + 1; j < n; j++)
//         {
//             if(a[j] < a[min])
//                 min = j;
//         }

//         temp = a[i];
//         a[i] = a[min];
//         a[min] = temp;
//     }
// }

// int main()
// {
//     int n, i;
//     printf("Enter number of elements: ");
//     scanf("%d", &n);

//     int a[n];

//     // Generate random numbers
//     srand(time(0));

//     for(i = 0; i < n; i++)
//     {
//         a[i] = rand() % 10000;
//     }

//     // Start time
//     clock_t start = clock();

//     selectionSort(a, n);

//     // End time
//     clock_t end = clock();

//     double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

//     // Display sorted array
//     // printf("\nSorted Array:\n");
//     // for(i = 0; i < n; i++)
//     // {
//     //     printf("%d ", a[i]);
//     // }

//     // Time Complexity
//     printf("\n\nTime Complexity: O(n^2)");
//     printf("\nExecution Time: %f seconds\n", time_taken);

//     return 0;
// }

void selectionSort(int arr[], int n){
    int i,j,min;
    for(int i = 0; i<n-1; i++){
        min = i;
        for(int j = i+1; j<n; j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] =temp;
    }
}
int main(int argc, char const *argv[])
{
    int n,i;
    printf("Enter the number of element: ");
    scanf("%d",&n);
    int arr[n];
    srand(time(0));
    for(int i = 0; i<n; i++){
        arr[i] = rand()%1000;
    }

    clock_t start = clock();
    selectionSort(arr,n);
    clock_t end = clock();
    double timeTaken = (double)(end-start)/CLOCKS_PER_SEC;
    printf("\nTotal time taken: %f",timeTaken);
    printf("\nTime complexity: O(n^2)");
    return 0;
}

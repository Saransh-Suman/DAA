#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Function to perform selection sort
void selectionSort(int arr[], int n)
{
int i, j, min_idx,temp;
// One by one move boundary of unsorted subarray
for (i = 0; i<=n-2; i++)
{
// Find the minimum element in unsorted array
min_idx = i;
for (j = i+1; j <=n-1; j++)
{
if (arr[j] <arr[min_idx])
min_idx = j;
}
// Swap the found minimum element with the first element
temp=arr[i];
arr[i]=arr[min_idx];
arr[min_idx]=temp;
}
}
int main()
{
int n ;// Number of elements
printf("enter the value of n\n");
scanf("%d",&n);
int arr[n];
srand(time(NULL)); // Seed for random number generation
// Generate random numbers and fill the array
printf("Original Array: ");
for (int i = 0; i< n; i++)
{
arr[i] = rand() % 10000; // Generating random numbers between 0 and 999
printf("%d ", arr[i]);
}
printf("\n");
// Perform selection sort
double clock_tstart_time = clock();
selectionSort(arr, n);
double clock_tend_time = clock();
double total_time = (double)(clock_tstart_time - clock_tend_time) /
CLOCKS_PER_SEC;
// Display sorted array
printf("Sorted Array: ");
for (int i = 0; i< n; i++)
{
printf("%d ", arr[i]);
}
printf("\n");
// Print time complexity
printf("Time Complexity: O(n^2)\n");
printf("Execution Time: %f seconds\n", total_time);
return 0;
}

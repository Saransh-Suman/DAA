// Design and implement C/C++ Program to sort a given set of n integer elements using
// Selection Sort method and compute its time complexity. Run the program for varied values of
// n> 5000 and record the time taken to sort. Plot a graph of the time taken versus n. The
// elements can be read from a file or can be generated using the random number generator.

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void selectionSort(int arr[],int n){
    int i,j,min_idx;
    for(i = 0; i<n-2; i++){
        min_idx = i;
        for(j = i+1; j<n-1; j++){
            if(arr[j]<arr[min_idx])
                min_idx = i;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n; i++){
        arr[i]=rand()%1000;
    }
    double clock_tstart_time = clock();
    selectionSort(arr,n);
    double clock_tend_time = clock();
    double totalTime = (double)(clock_tend_time-clock_tstart_time )/CLOCKS_PER_SEC;
    printf("Total time: %f",totalTime);
    return 0;
}

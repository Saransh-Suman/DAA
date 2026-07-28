// Design and implement C/C++ Program to sort a given set of n integer elements using Merge Sort
// method and compute its time complexity. Run the program for varied values of n> 5000, and
// record the time taken to sort. Plot a graph of the time taken versus n. The elements can be read
// from a file or can be generated using the random number generator.
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 1000000
void merge(int arr[],int low,int mid,int high){
    int start = low;
    int m = mid+1;
    int temp[MAX];
    int i = start;
    while(start<=m && m<=high){
        if(arr[start]<arr[mid]){
            temp[i++]=arr[start++];
        }
        else{
            temp[i++]=arr[mid++];
        }
    }
    while(start<=m){
        temp[i++] = arr[start++];
    }
    while(m<=high){
        temp[i++] = arr[m++];
    }
}
void mergeSort(int arr[],int low,int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i<n;i++){
        arr[i] = rand()%1000;
    }
    double start = clock();
    mergeSort(arr,0,n-1);
    double end = clock();
    double totalTime = (double)(end-start)/CLOCKS_PER_SEC;
    printf("Total time taken: %f",totalTime);
    return 0;
}

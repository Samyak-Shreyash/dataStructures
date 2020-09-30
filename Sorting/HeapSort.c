#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int* arr, int n, int i)
{
    int lrgest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < n && arr[l] > arr[lrgest])
    lrgest = l;
    if(r < n && arr[r] > arr[lrgest])
    lrgest = r;
    if(lrgest != i)
    {
        swap(&arr[i], &arr[lrgest]);
        heapify(arr, n, lrgest);
    }
}
void heapSort(int* arr, int n)
{
    int i;
    for(i = n/2-1; i >= 0; i--)
        heapify(arr,n,i);
    
    for(i = n-1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void printArr(int* arr, int n)
{
    printf("\nSorted Array: ");
    int i;
    for(i = 0;i < n;i++)
        printf("%d ", arr[i]);
}
int main()
{
    int n, i;
    scanf("%d",&n);
    int arr[n];
    for(i = 0;i < n;i++)
    {
        scanf("%d",&arr[i]);
    }
    heapSort(arr, n);
    printArr(arr, n);
    return 0;
}





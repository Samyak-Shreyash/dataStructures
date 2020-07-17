#include<stdio.h>

int swap(int *a, int*b)
{
    int c=*a;
    *a=*b;
    *b=c;
}

int InsertionSort(int *arr, int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
                swap(&arr[i],&arr[j]);
                
        }
    }
}

int printArr(int *arr, int n)
{
    printf("\nSorted Array is : ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);            
    InsertionSort(arr,n);
    printArr(arr,n);
    return 0;
}
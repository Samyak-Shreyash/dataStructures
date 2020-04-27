#include<stdio.h>
int swap(int *a, int*b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int BubbleSort(int *arr, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(arr[i]<arr[j])
                swap(&arr[i],&arr[j]);
        }
    }
}

int printArr(int *arr, int n)
{
    printf("\nSorted Array is : ");
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);            
    BubbleSort(arr,n);
    printArr(arr,n);
    return 0;
}
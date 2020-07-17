#include<stdio.h>
int swap(int *a, int*b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
int SelectionSort(int *arr, int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(i!=min)
            swap(&arr[i],&arr[min]);
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
    SelectionSort(arr,n);
    printArr(arr,n);
    return 0;
}
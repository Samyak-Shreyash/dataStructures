#include<stdio.h>

void printArr(int arr[], int n)
{
    printf("\nSorted Array: \n");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
    printf("\n");
    
}

void swap(int *a, int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}

int partition(int arr[], int lo,int hi)
{
    int piv=arr[hi];
    int i=lo,j=lo;
    while(j<=hi)
    {
        if(arr[j]<piv)
        {
            if(i!=j)
            {
                swap(&arr[i],&arr[j]);          
            }
            i++;
        }
        j++;
    }
    swap(&arr[i],&arr[hi]);
    return i;
}

void quickSort(int arr[],int lo, int hi)
{
    if(lo<hi)
    {
    int pivot=partition(arr,lo,hi);
    quickSort(arr,lo,pivot-1);
    quickSort(arr,pivot+1,hi);
    }    
    
    
}
int main()
{
 int n;
 printf("Enter Array Size: ");
 scanf("%d",&n);
 int arr[n],i;
 printf("Enter Array Elements: ");
 for(i=0;i<n;i++)
 {
     scanf("%d",&arr[i]);
 }
 quickSort(arr,0,n-1);
 printArr(arr,n);
 return 0;
}
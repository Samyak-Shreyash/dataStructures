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

void partition(int arr[], int lo,int hi,int *i,int *j)
{
    int piv=arr[lo];
    int lt=lo,gt=hi;
    *i=lt;
    *j=hi;
    while(lt<=gt)
    {
        if(arr[lt]>piv)
        {
            swap(&arr[lt],&arr[gt]);
            gt--;
        }
        else
        {        
            if(arr[lt]<piv)
            {
                swap(&arr[lo],&arr[lt]);
                lo++;
            }
            lt++;
        }
    }
    *j=gt;
    *i=lo;
}

void quickSort(int arr[],int lo, int hi)
{
    if(lo>hi)
    return ;
    int i,j;
    partition(arr,lo,hi,&i,&j);
    quickSort(arr,lo,i-1);
    quickSort(arr,j+1,hi);
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
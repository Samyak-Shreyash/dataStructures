#include<stdio.h>
int getSubset(int* arr, int n)
{
    int i,rsum=0,lsum=0;
    for(i=0;i<n;i++)
        rsum+=arr[i];
    
    for(i=0;i<n&&lsum<rsum;i++)
    {
        rsum-=arr[i];
        lsum+=arr[i];
        if(lsum==rsum)
            return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf(" %d",&arr[i]);
    printf("Result: %d ",getSubset(arr, n));
    return 0;
}
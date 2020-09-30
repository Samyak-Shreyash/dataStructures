#include<stdio.h>

int getSubset(int* arr, int n, int sum)
{

    if(sum == 0)
        return 1;
    if(n==0)
        return 0;
    if(arr[n-1]>sum)
       return getSubset(arr, n-1, sum);
    else
        return (getSubset(arr, n-1, sum-arr[n-1]) || getSubset(arr, n-1, sum));


}
int main()
{
    int n,sum=0;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)
    {
        scanf(" %d",&arr[i]);
        sum+=arr[i];
    }
    if(sum%2)
    printf("Result: 0 ");
    else
    {
     sum/=2;
     printf("Result: %d ",getSubset(arr, n, sum));
    }
    
    return 0;
}
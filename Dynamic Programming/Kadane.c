#include<stdio.h>
int CalculateMaxSum(int *arr, int n)
{
    int max_sum=arr[0],max_ending_here=arr[0],i;
    for(i=1;i<n;i++)
    {  
        max_ending_here=max_ending_here+arr[i];
        if(max_sum<max_ending_here)
            max_sum=max_ending_here;
        if(max_ending_here<0)
            max_ending_here=0;
    }
    return max_sum;
}
int main()
{
    int n,sum;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    sum=CalculateMaxSum(arr,n);
    printf("Max Continuous Sum is %d\n",sum);    
    return 0;
}
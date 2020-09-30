#include<stdio.h>
int getSubArr(int* arr, int i, int k, int n)
{
    // printf("Strt. Pos: %d, Sum: %d, \n",i,k);
    int sum=0,pos=i;
    while(sum<k && i<n)
    {
        sum+=arr[i];
        i++;
    }
    // printf("Sum: %d \n",sum);
    if(sum==k)
        return (getSubArr(arr,i,k,n)+1);
    if(i==n)
        return 0;
    if(sum>k)
        return getSubArr(arr,pos+1,k,n);

}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n],i,k;
    for(i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("Enter Sum Value: ");
    scanf("%d",&k);
    printf("Total Count is: %d\n",getSubArr(arr,0,k,n));
}
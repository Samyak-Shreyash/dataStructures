#include<stdio.h>

int jumpGame(int* arr, int n, int pos, int steps)
{
    printf("Pos: %d   Step: %d \n",pos, arr[pos]);
    if(pos>=n-1)
        return steps;
    if(arr[pos]<1)
        return 0;
    int min =__INT32_MAX__;
    for(int i=1;i<=arr[pos]&&i<n;i++)
    {
        int res  = jumpGame(arr, n, pos+arr[i], steps+1);
        if(res<min)
            min=res;
    }
    return min;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans = jumpGame(arr,n,0,1);
    if(ans>0)
        printf("Min. Jump required is: %d\n",ans);
    else
        printf("Cannot reach end\n");
    return 0;

}
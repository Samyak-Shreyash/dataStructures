#include <stdio.h>
int getMax(int a, int b)
{
    return a>b?a:b;
}
int knapSack(int* val, int* wt, int W, int n)
{
    if(W==0 || n==0)
    {
        return 0;
    }
    if(wt[n-1]<=W)
    {
        return getMax((val[n-1]+knapSack(val, wt, W-wt[n-1], n-1)), knapSack(val, wt, W, n-1));        
    }
    else
    {
        return knapSack(val, wt, W, n-1);
    }
        
}
int main()
{
    int n,W;
    scanf("%d",&n);
    int val[n], wt[n], i;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&wt[i],&val[i]);
    }
    scanf("%d",&W);
    printf("%d ",knapSack(val, wt, W, n));
    return 0;
}

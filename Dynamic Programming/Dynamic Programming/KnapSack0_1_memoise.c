#include <stdio.h>
#include <string.h>
static int t[101][101];
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
    if (t[n][W]!=-1)
    {
        return t[n][W];
    }   
    if(wt[n-1]<=W)
    {
        return t[n][W] = getMax((val[n-1]+knapSack(val, wt, W-wt[n-1], n-1)), knapSack(val, wt, W, n-1));        
    }
    else
    {
        return t[n][W] = knapSack(val, wt, W, n-1);
    }
        
}
int main()
{
    int n,W;
    memset(t,-1,sizeof(t));
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

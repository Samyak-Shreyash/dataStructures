#include <stdio.h>
#include <string.h>
static int t[101][101];
int getSum(int * wt, int n)
{
    int sum=0;
    while (n>0)
        sum+=wt[--n];
    
    
}
int getMax(int a, int b)
{
    return a>b?a:b;
}
int knapSack(int* val, int* wt, int W, int n)
{
    int sz = getMax(getSum(wt, n), W);
    int t[n][sz];
    memset(t,-1,sizeof(t));
    int i,j,nw;
    for(i = 0; i <= n; i++)
    {
        for (j = 0; j <= sz; j++)
        {
            nw = -1;
            if(i == 0 || j == 0)
            {
                t[i][j]=0;
            }
            else if(wt[i-1]<=j)
            {
                nw=j-wt[i-1];
                t[i][j] = getMax((val[i-1]+t[i-1][nw]), t[i-1][j]);
            }
            else
            {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][W];
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
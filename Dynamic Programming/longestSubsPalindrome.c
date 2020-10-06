#include<stdio.h>
#include<string.h>
void LongSubsPal(char* st, int n)
{
    int dp[n][n];
    int i, j, k, strt=0, maxLength=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
            dp[i][j]=0;
        dp[i][i]=1;
    }
    for(i=0;i<n;i++)
        if(st[i]==st[i+1])
        {
            dp[i][i+1];
            strt =i;
            maxLength=2;
        }
    for(k=3;k<n;k++)
    {
        for(i=0;i<n;i++)
        {   
            j=(i+k-1);         
            if(dp[i+1][j-1] && st[i]==st[j])

            if(dp[i+1][j-1] && st[i]==st[j])
            {
                dp[i][j]=1;
                if(k>maxLength)
                {
                    strt = i;
                    maxLength = k;
                }
            }
        }
    }
    printf("%d %d\n",strt, maxLength);
    for(i=0; i<maxLength; i++)
    {
        printf("%c",st[i+strt]);
    }
    printf("\n");

}
int main()
{
    char st[100];
    scanf("%[^\n]%*c", st);
    int n= strlen(st);
    // printf("%d ",n);
    LongSubsPal(st,n);
    return 0;
}
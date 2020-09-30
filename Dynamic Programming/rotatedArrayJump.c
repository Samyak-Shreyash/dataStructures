#include<stdio.h>
int min(int a, int b) { return a<b?a:b;}

int jumpGame(int* arr, int n)
{
    if(arr[0]==0)
        return -1;
    int jumps[n];
    int prev_min = __INT32_MAX__;   
    for(int i=n-1;i>=0;i--)
    {
        jumps[i]=__INT32_MAX__-1;
        if(arr[i]>0)
        {
            if(arr[i]+i>=n-1)
                jumps[i]=1;
                for(int j= arr[i]+i;j>i&&jumps[i]>prev_min;j--)
                {
                    // printf("I_JMP: %d J_JMP: %d ",jumps[i],jumps[j]);
                    jumps[i]=min(jumps[i],jumps[j]+1);
                }    
        printf("\nPos: %d Val: %d Jump: %d\n",i+1,arr[i],jumps[i]);
        prev_min =min(prev_min,jumps[i]);
    }
    }
    if(jumps[0]==__INT32_MAX__-1)
    jumps[0]=-1;

    return jumps[0];
}
void getJumps(int* arr, int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            int ans= jumpGame(arr,n);
            if(ans!=-1)
            {
                printf("%d\n",ans);
                return ;
            }
        }
    }
    
    printf("-1\n");
    
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n],i,strt,j;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    scanf("%d",&strt);
    int sec_arr[n];
    for(i=0;i<n;i++)
    {
        j=(i+strt)%n;
        sec_arr[i]=arr[j];
        printf("%d ",sec_arr[i]);
    }
    printf("\n");
    getJumps(sec_arr,n);
    return 0;
}
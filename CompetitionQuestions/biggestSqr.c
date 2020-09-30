#include<stdio.h>
#include<stdlib.h>
int min(int a, int b, int c)
{
    return (a<b)?((a<c)?a:c):((b<c)?b:c);
}

int getBigSqr(int** arr, int m, int n)
{
    int i,j,max=0;
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            if(arr[i][j]==1)
            {
                arr[i][j]= min(arr[i][j-1],arr[i-1][j-1],arr[i-1][j])+1;
                if(arr[i][j]>max)
                {
                    max=arr[i][j];
                }
                }
        }
    }
    return (max*max);
}

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int** arr;
    arr=(int**)malloc(m*sizeof(int*));
    int i,j;
    for(i=0;i<m;i++)
    {
        arr[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Area of biggest Square is: %d\n",getBigSqr(arr,m,n));    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int min(int a, int b)
{
    return a<b?a:b;
}
int solveGrid(int** arr, int n, int i, int j)
{
    if(i == n-1 && j == n-1)
        return 1;
    if(arr[i][j]==0)
        return 0;
        return (solveGrid(arr, n, i+1, j) || solveGrid(arr, n, i+1, j));     
}
int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int** arr= (int**)malloc(n*sizeof(int*));
    for (i = 0; i < n; i++)
    {
    arr[i]= (int*)malloc(n*sizeof(int));
      for(j=0;j<n;j++)
      {
          scanf("%d",&arr[i][j]);
      }
    }
    printf("%d ",solveGrid(arr, n, 0, 0));
    return 0;
}
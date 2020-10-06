/*
Gettng Position for all queens in a nxn Chess board 
*/

#include <stdio.h>
void printQueens(int* arr, int n)
{
    int i;
    printf("[");
    for(i=0;i<n;i++)
    {
        printf("%d ",(arr[i]+1));
    }
    printf("] ");
}

int isBoardSafe(int* arr, int row, int col)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        j=arr[i];
        if(col == j || row+col == i+j || row-col == i-j)
            return 0;
    }
    return 1;
}
int solveNQueen(int* arr, int n, int row)
{
    // printf("\n Row %d: ",row);
    if(row == n)
    {
        printQueens(arr,n);
        return 1;
    }
    int res = 0;
    for(int i=0;i<n;i++)
    {
    // printf(" Col %d ",i);
        if(isBoardSafe(arr, row, i))
        {
            arr[row]=i;
            if(solveNQueen(arr, n, row+1) || res)
                res=1;
            arr[row]=-1;
        }
    }
    return res;
}
void nQueen(int n)
{
    int arr[n], i;
    for(i=0;i<n;i++)
        arr[i]=-1;
    if(solveNQueen(arr,n,0)==0)
    {
        printf("No Solution exists\n");
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t-->0)
    {
    int n;
    scanf("%d",&n);
    nQueen(n);
    printf("\n");
    }
    return 0;
}

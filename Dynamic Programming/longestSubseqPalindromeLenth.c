#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
    return a>b?a:b;
}
int LongSubsPal(char* str, int l,int r)
{
    if(l>r)
        return 0;
    if(l==r)
        return 1;
    if(str[l]==str[r])
    return LongSubsPal(str,l+1,r-1)+2;
    return max(LongSubsPal(str,l+1,r),LongSubsPal(str,l,r-1));
}
int main()
{
    char st[100];
    scanf("%[^\n]%*c", st);
    int n= strlen(st);
    // printf("%d ",n);
    printf(" %d\ns",LongSubsPal(st,0,n-1));
    return 0;
}
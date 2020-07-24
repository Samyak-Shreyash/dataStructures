#include<stdio.h>
    int removeDigit1(int x,int dig1)
    {
        printf("Before Removal : %d\n",x);
        int div=10;
        while(x>=div)
        {
            div*=10;
        }
        int num= x%(div/10);
        printf("X: %d -- Num: %d -- Div: %d -- Diff: %d", x, num, div, x-num);

        if(x-num>div-1)
        return -1;
        return num; 
    }
    int getDigit1(int x)
    {
        printf("\nGetDigit :%d\n",x);
        if(x==0)
        return 0;
        int div=10;
        while(x>=div)
        {
            div*=10;
        }
        printf("Num: %d -- Div: %d ", x, div);
        return x/(div/10);
    }
    int isPalindrome(int x) {
        printf("%d \t", x);
        if(x>-1&&x%10==x)
            return 1;
        if(x<0&&x%10==0)
            return 0;
        int dig1=getDigit1(x);
        printf("\nDig1: %d -- DigLast:  %d\n", dig1, x%10);
        if ((x%10)==dig1)
        {
            int num= removeDigit1(x/10, dig1);
            return isPalindrome(num);
        }
            
        return 0;
    }
int main()
{
    int x;
    int n=-2%10;
    printf("%d ",n);
    scanf("%d",&x);
    printf("\nOutput: %d ", isPalindrome(x));
    return 0;
}
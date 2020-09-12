#include<stdio.h>
int main()
{
    int n,i,ar,min=__INT32_MAX__,minVal;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar);
        if((abs(ar)<=min))
        {
            minVal=ar;
            if((abs(min)==min)&& minVal!=abs(ar))
            {
                minVal=abs(ar);
                min=abs(ar);
            }
        }
    }
    printf("%d",minVal);
    return 0;
}
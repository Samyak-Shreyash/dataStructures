#include<stdio.h>

unsigned getNthUglyNo(unsigned n) 
{ 
    unsigned ugly[n]; // To store ugly numbers 
    unsigned i2 = 0, i3 = 0, i5 = 0; 
    unsigned n2 = 2; 
    unsigned n3 = 3; 
    unsigned n5 = 5; 
    unsigned nextUgly = 1; 

    ugly[0] = 1; 
    for (int i=1; i<n; i++) 
    { 
        nextUgly = min(n2,min(n3,n5)); 
        ugly[i] = nextUgly; 
        if (nextUgly == n2) 
            n2 = ugly[++i2]*2; 
        if (nextUgly == n3) 
            n3 = ugly[++i3]*3; 
        if (nextUgly == n5) 
            n5 = ugly[++i5]*5; 
    } 
    return nextUgly; 
} 

int main() 
{ 
    int n;
    scanf("%d",&n);
    printf("%dth Ugly number is : %d\n",getNthUglyNo(n)); 
    return 0; 
} 
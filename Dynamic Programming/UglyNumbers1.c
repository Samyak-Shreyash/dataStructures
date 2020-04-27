# include<stdio.h> 

int maxDivide(int a, int b) 
{ 
    while (a%b == 0) 
        a/=b;  
    return a; 
}     


int isUgly(int no) 
{ 
    no = maxDivide(no, 2); 
    no = maxDivide(no, 3); 
    no = maxDivide(no, 5); 
    
    return (no == 1)? 1 : 0; 
}   

int getNthUglyNo(int n) 
{ 
    int i = 1;  
    int count = 1;   /* ugly number count */ 

    while (n > count) 
    { 
        if (isUgly(++i)) 
            count++;  
    } 
    return i; 
} 

int main() 
{ 
    int n;
    scanf("%d",&n);
    printf("%dth ugly no. is %d ", n, getNthUglyNo(n));
    return 0; 
} 
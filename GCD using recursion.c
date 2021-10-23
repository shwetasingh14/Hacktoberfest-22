#include <stdio.h>

int GCD(int n,int m)
{
    if(m==0)
        return n;
    return GCD(m,n%m);
}

int main()
{
    int n,m,gcd;
    printf("Enter first number: ");
    scanf("%d",&n);
    printf("\nEnter second number: ");
    scanf("%d",&m);
    gcd=GCD(n,m);
    printf("\nGCD of %d and %d is: %d",n,m,gcd);
    return 0;
}

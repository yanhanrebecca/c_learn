#include <stdio.h>
int main( )
{
    int a,b,c,d;
    scanf("%d",&a);
    b= a/100;
    c= (a%100) /10;
    d=a%10;
    printf("%d",100*d+10*c+b);
    return 0;
}
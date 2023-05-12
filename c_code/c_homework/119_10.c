#include <stdio.h>
int main()
{
    int a,b,c,d;
    printf("Please input 3 NUM:\n");
    scanf("%d,%d,%d",&a,&b,&c);
    d=c;
    c=b;
    b=a;
    a=d;
    printf("a=%d,b=%d,c=%d",a,b,c);
    return 0;
}
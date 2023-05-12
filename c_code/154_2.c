#include <stdio.h>
int main()
{
    int x = 0;
    int y = 0;
    scanf("%d", &x);
    if(x<0)
        y = -1;
    else if(x == 0)
        y = 0;
    else
        y = 1;
    
    printf("%d\n", y);
    return 0;
}
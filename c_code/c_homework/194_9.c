#include <stdio.h>
void cooperation()
{
    int n,i = 0, m, sum = 0;
    scanf("%d",&n);
    while(n!=0)
    {
        m = n % 10;//得出正数的每一位数字 
        sum += m;//并求和 
        n /= 10;//求出包含的位数 
        i++;//对位数进行计数 
    }
    printf("%d\n", sum);
}
int main()
{
    cooperation();
    return 0;
}
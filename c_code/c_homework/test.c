#include <stdlib.h>  //清屏
#include <stdio.h>
int main()
{
    int a[100] = {1, 2, 3}, i = 1, k = 94, n = 3;
    for(int j = n + 1; j > i; j--)
    {
        a[j] = a[j - 1]; 
    }
    a[i] = k;
    n += 1;
    for(int i = 0; i < n; i++){
         printf("%d, ", a[i]);
    }
    printf("数组长度是:%d", n);

}
#include<stdio.h>
int main()
{
	int i, j, k, n;
	printf("所有的水仙花数有：");
	for(n = 100; n < 1000; n++)
	{
		i = n / 100;       //分出百位数字 
		j = (n - i * 100) / 10;        //分出十位数字
	    k = n % 10;        //分出个位数字
		if(n == i * i * i + j * j * j + k * k * k){
			printf("%d ,", n);
			 }
	}
    printf("\n");
}
#include<stdio.h>
/* 
斐波那契数列: 斐波那契数列（Fibonacci sequence），又称黄金分割数列，因数学家莱昂纳多·斐波那契
（Leonardo Fibonacci）以兔子繁殖为例子而引入，故又称为“兔子数列”，指的是这样一个数列：1、1、2、3
、5、8、13、21、34、……。在数学上，斐波那契数列以如下被以递推的方法定义：F(1)=1, F(2)=1, 
 F(n)=F(n - 1)+F(n - 2)（n ≥3，n ∈ N*）.
 */
int Fibon(int n)
{
   if (n == 1|| n == 2)
   {
	   return 1;
   }
   else
   {
	   return Fibon(n-1)+ Fibon(n-2);
   }
}


int main()
{
	for (int i = 1; i <= 40; i++)
	{
		printf("%d ", Fibon(i));
	}
	return 0;
}
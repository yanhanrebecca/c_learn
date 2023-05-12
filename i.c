
#include<stdio.h>
#include<stdlib.h>
int main()
 {
   int num1;
   int num2;
   int num3;//声明并定义变量；
   
   printf("请输入第一个加数：\n");//提示用户输入第一个操作数；
   scanf("%d",&num1);//scanf函数扫描第一个数；
   
   printf("请输入第二个加数：\n");//提示用户输入第二个操作数；
   scanf("%d",&num2);//scanf函数扫描第二个数；
                     //扫描用户输入的操作数要定义变量，并且要取变量地址；
  
   num3=num1+num2;//计算结果；
   
   printf("IT男超哥很帅！！！\n");
   printf("IT男超哥yyds！！！\n");//printf函数的基本格式("输出的结果\n，输出格式")，不要忘记分号；
   
   printf("结果：%d+%d=%d\n",num1,num2,num3);//占位符：%d代表在输出的地方，占了一个坑，输出结果根据逗号后面的变量名的变量值输出；
   
   return 0;            //return和int成对出现，无int就没有return；

 }
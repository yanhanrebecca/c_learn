//计算学生五门课的平均成绩、最高分和最低分
#include<stdio.h>
#include<stdlib.h>
int ave(int a[]);
int min(int a[]);
int min_y(int a[]);
int max(int a[]);
int main(){
int a[5],i,b,c,d,e;
printf("请输入五门课成绩");
for ( i = 0; i < 5; i++)
{
    scanf("%d",&a[i]);
}
b=ave(a);
c=max(a);
d=min(a);
e = min_y(a);
printf("平均成绩%d，最高分%d，最低分为%d,修改最低分",b,c,d,e);
system("pause");
return 0;
}

int ave(int a[]){
    int A=0,i;
    for ( i = 0; i < 5; i++)
    {
        A=A+a[i];
        
    }
    return A/5;
    
}
int min(int a[]){
    int i,j,t;
    printf("ceshi  min");
    for ( i = 0; i < 5; i++)
        {
            printf("%d  ",a[i]);
        }
    for ( i = 1; i < 5; i++)
    {
      printf("i:%d ", i);
        for (j = 0; j<5-i; j++)
    {
        printf("j:%d ",j);
        if (a[j]>a[j+1])
        {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
        
    }
    printf("ceshi  min");
    for ( i = 0; i < 5; i++)
        {
            printf("%d  ",a[i]);
        }
        
        return a[0];
        
    }}
    

int min_y(int a[]){
    int i,j,t;
    printf("ceshi  min_y");
    for ( i = 0; i < 5; i++)
        {
            printf("%d  ",a[i]);
        }
        for (i = 0; i < 4; i++) { // 外层循环需要进行四次，内层循环需要完全排序
        for (j = 0; j < 4 - i; j++) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("ceshi  min_y");
    for ( i = 0; i < 5; i++)
        {
            printf("%d  ",a[i]);
        }
        
        return a[0];
        
    }
    

int max(int a[]){
    int i,j,t;
    for ( i = 1; i < 5; i++)
    {
        
        for ( j= 0; j < 5-i; j++)
        {
            if (a[i]>a[i+1])  //升序排列
            {
                t=a[i];
                a[i]=a[i+1];
                a[i+1]=t;
            }
            
        }
        return a[4];
        
    }
    
}
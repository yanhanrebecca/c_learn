#include<stdio.h>
void in(int m,int n, int a[m][n]);
int out(int m,int n, int a[m][n]);
// void disp(a);
int main(){
  int num,m=3,n=4,a[m][n];
  in(m, n, a);
  // while (1)
  // {
  //    printf("请输入你想要进行的操作:0.退出程序 1.输入二维数组 2.计算所有元素和\n");
  //    switch (num)
  //    {
  //    case 1:
  //     in(a,m,n);
  //     disp(a);
  //     break;
  //    case 2:
  //     out(a,m,n);
  //     break;
  //    case 0:
  //     return 0;
  //     break;
  //    }
  // }
}
void in(int m,int n, int a[m][n]){
  int i,j;
  printf("请输入数组元素");
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      scanf("%d",&a[i][j]);
    }
  }
}
#include<stdio.h>
void in(int m,int n, int a[m][n]);  
int out(int m,int n, int a[m][n]);
void disp(int m, int n,int a[m][n]);

int main(){
  int m=3,n=4,a[m][n];
  
  in(m, n, a); 
  disp(m, n, a);
  out(m, n, a);  
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

int out(int m,int n, int a[m][n]){
  int i,j,sum=0;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
      sum+=a[i][j];
    }
  }
  printf("数组元素之和为:%d",sum);
  return 1;
}  

void disp(int m, int n,int a[m][n]){
  int i,j;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++){
       printf("%d ",a[i][j]); 
    }
    printf("\n");
  }
}
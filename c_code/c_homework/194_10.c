/*原整型数依次取余，将所得余数构造成一个新整型数，判断新整型数
与原整型数是否一致。若一致，则该整型数是回文数，若不一致，则该
整型数不是回文数。*/
#include<stdio.h>
int main(){
	int n, s, y = 0;
	printf("请输入所要进行判断的数字：");
	scanf("%d", &n);
	s = n; 
	while(s > 0){
		y = s % 10 + y * 10;
		s = s / 10;
	}
	if(y == n){
		printf("%d是回文数", n);
	}else{
		printf("%d不是回文数", n);
	} 
}
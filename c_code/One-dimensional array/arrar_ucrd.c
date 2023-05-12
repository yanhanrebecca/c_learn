#include <stdio.h>
#include <stdlib.h>  //清屏
void sort (int a[],int n);                //排序
int search(int a[],int n,int k);          //查找
int insert(int a[],int n,int i,int k);    //插入
int delete(int a[],int n,int k);          //删除
void disp(int a[],int n);                 //输出


//主函数
int main()
{
    int i, n, search_success,k,a[100],tt, option_num,t=0;    
    //按键盘输入初始化一个含有n个整数的一维数组a[]
    printf("请输入数组元素个数：\n");
    scanf("%d", &n);
    printf("请输入%d个数：\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }       
    while(1){
        printf("--------------------------------------------------------\n\n");
        printf("请输入你想做的操作 1 排序 2 查找 3 插入 4 刪除 5 輸出 0 結束 ：\n");
        scanf("%d", &option_num);
        switch(option_num)
        {
            case 0: {
                return 0; 
            }
            case 1: {
                //a是数组,n是数组长度
                sort(a, n);
                break; 
            }
            case 2: 
                //查找（按值k查找下标）
                printf("请输入想查找的值:"); 
                scanf("%d", &k);
                search_success = search(a, n, k); 
                if(search_success != -1){
                    printf("查找成功，下标为%d\n", search_success);
                }
                else{
                    printf("查找失败\n");
                } 
                break;

            case 3: 
                printf("请输入插入的位置(下标),和插入的值，中间用回车隔开:\n"); 
                scanf("%d", &i); 
                scanf("%d", &k);
                //在长度为n的a数组的i位置插入k值，数组长度加一
                n = insert(a, n, i, k);
                disp(a, n);
                break;

            case 4: {
                //删除（按值k）
                printf("请输入删除的值:\n");
                scanf("%d", &k); 
                n=delete(a, n, k); 
                if(n < 0){
                    disp(a, n);
                    printf("删除失败\n");
                }
                else
                    disp(a, n);
                break;
            }
            case 5: {
                disp(a, n);
                break;
            }
            default: printf("输入错误！\n"); 
        }
    }
}


//排序(此处为冒泡)
void sort (int a[], int n)                
{
    int i, j, t;
    for(i = 0; i < n-1; i++)    //变量i代表比较的趟数 
        for(j = 0; j < n - 1 - i; j++)    //变最j代表每趟两两比较的次数
            if(a[j] > a[j + 1])
            {
                t = a[j];    //利用中间变量实现两值互换
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        printf("排序已完成！排序后的结果是：");
    for(i = 0; i < n; i++) {
        printf("%5d", a[i]);
    }
    printf("\n");
    getchar();

}


//查找（按值k查找下标）
int search(int a[],int n,int k)          
{
    int i;
    for(i = 0; i < n;i++)
        if(a[i] == k)
        {
        	return i;
        }
    return -1;
}


//在长度为n的a数组的i位置插入k值，数组长度加一
int insert(int a[],int n,int i,int k)    
{
    if(i >= 99){
        printf("超过数组最长限制，插入失败");
        return n;
    }
    if (n != 0){
        for(int j = n + 1; j > i; j--)
        {
            a[j] = a[j - 1]; 
        }
    }
    a[i] = k;
    return n + 1;
}


//删除值为k的元素
int delete(int a[],int n,int k)          
{
    int flag=0,i,j,t,jishu;
    for(i = 0; i < n; i++)
    {    
        if(a[i] == k){
            flag = 1;
            for(j = i; j < n - 1; j++){
                a[j] = a[j+1];   
            }
            return n - 1;
        }
        }
        return -1;
}


//输出数组长度和元素
void disp(int a[], int n)                 
{
    int i;
    printf("目前长度是%d的数组a包含如下元素：\n", n);
    printf("[");
    for(i = 0; i < n; i++)
        if(i == n - 1){
            printf("%d", a[i]); 
        }
        else{
            printf("%d,", a[i]);
        }   
    printf("]");
    printf("\n");
}
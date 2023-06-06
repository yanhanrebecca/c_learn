#include <stdio.h>
#include <stdlib.h>  //清屏
//函数的声明
/*
这里使用a[][m]作为函数参数类型,而不是a[n][m]或者a[][],有以下原因:
1. a[n][m] - 这种定义方式是指定了具体的行数n和列数m,那么在调用函数时,就必须传入大小严格为n*m的二维数组,否则会报编译错误。
这减少了函数的灵活性和通用性。
2. a[][] - 这种定义只指定了二维数组,但没有指定列数,这在调用函数时允许传入各种列数的二维数组,增加了灵活性,但是在函数内部操
作数组时,无法知道具体的列数,会比较麻烦。
3. a[][m] - 这种定义指定了二维数组,并指定了列数为m,那么:
- 在调用函数时,允许传入任意行数,但列数必须为m的二维数组,这增加了一定灵活性。
- 在函数内部,知道具体的列数m,可以方便的操作数组,这增加了方便性。
所以,a[][m]的定义方式兼顾了灵活性和方便性,程序员在调用函数时只需要确保传入数组的列数为m,就可以传入任意行数的二维数组,这增强了
函数的适用性。而在函数内部,程序员也知道数组的列数为m,可以方便的操作数组。
*/
void sort(int n, int m, int a[][m]);             //排序
struct Position search(int n, int m, int a[][m], int key);       //查找
void modify(int n, int m, int a[][m], int key, int new_val);  //修改
int delete_val(int n, int m, int a[][m], int key);       //删除
void disp(int n, int m,int a[n][m]);                 //输出

struct Position {
    int row;
    int col; 
};
//主函数
int main()
{
    //按键盘输入初始化一个含有n * m个整数的二维数组a[][]
    int n, m, option_num, k, p;

    int row, col;
    printf("请输入数组行数和列数,用空格分开:\n");
    scanf("%d%d", &n, &m);
    int a[n][m];  
    for (int i = 0; i < n; i++) {
        printf("请输入第%d行的%d个元素:\n", i+1, m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]); 
        }
    }
    while(1){
        printf("--------------------------------------------------------\n\n");
        printf("请输入你想做的操作 1 排序 2 查找 3 修改 4 刪除 5 輸出 0 結束 ：\n");
        scanf("%d", &option_num);
        switch(option_num)
        {
            case 0: {
                return 0;
            }
            case 1: {
                sort(n, m, a);
                disp(n, m, a);
                break; 
            }
            case 2: 
                //查找（按值k查找下标）'
                printf("请输入想查找的值:"); 
                scanf("%d", &k);
                struct Position pos = search(n, m, a, k); 
                printf("result is %d, %d/n",pos.row, pos.col); 
                disp(n, m, a);
                break;

            case 3: 
                printf("请输入修改的元素，中间用回车隔开:\n"); 
                scanf("%d", &k); 
                scanf("%d", &p);
                //在长度为n的a数组的i位置插入k值，数组长度加一
                modify(n, m, a, k, p);
                break;

            // case 4: {
            //     //删除（按值k）
            //     printf("请输入删除的值:\n");
            //     scanf("%d", &k); 
            //     result=delete(a, n, k); 
            //     if(result == n){
            //         disp(a, result);
            //         printf("删除失败\n");
            //     }
            //     else
            //         disp(a, result);
            //     break;
            // }
            case 5: {
                disp(n, m, a);
                break;
            }
            default: printf("输入错误！\n"); 
        }
    }
}


//这个函数删除二维数组a中所有值为key的元素,并返回删除的元素总数count。由于删除元素后,
//数组大小变小,需要调整后续元素的位置,所以使用了一个额外的for循环进行元素移动。
int delete_val(int n, int m, int a[][m], int key) 
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == key) {
                count++;
                for (int k = j; k < m - 1; k++) {
                    a[i][k] = a[i][k + 1];
                }
                m--;
                j--;
            }    
        }
    }
    return count; 
}

/*
1. 把二维数组看成一位数组,计算全部元素个数n*m。
2. 外层for循环控制冒泡排序的趟数,排序趟数为n*m-1趟。
3. 内层for循环控制每趟比较和交换的次数,从0开始,到n*m-1-i。
4. 在内层循环中,使用j/m和j%m来获取当前元素的行索引和列索引,并与相邻元素比较和交换。
5. 重复步骤3和4,直到排序完成。
*/
void sort(int n, int m, int a[][m]) 
{ 
    int i, j;
    //外层for循环控制需要比较的趟数 
    for (i = 0; i < n * m - 1; i++) { 
        
        //内层for循环控制每趟比较的次数
        for (j = 0; j < n * m - 1 - i; j++) { 
            
            //如果相邻两个元素第一个大于第二个,则交换它们   
            if (a[j / m][j % m] > a[(j + 1) / m][(j + 1) % m]) {  
                int temp = a[j / m][j % m];
                a[j / m][j % m] = a[(j + 1) / m][(j + 1) % m];
                a[(j + 1) / m][(j + 1) % m] = temp;
            }
        }
    }
}

// 通过二维数组a查找值key,如果找到返回元素的行和列索引i和j,否则返回-1
struct Position search(int n, int m, int a[][m], int key) 
{
    struct Position pos;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == key) {
                pos.row = i; 
                pos.col = j;
                return pos; 
            } 
        }
    }
    pos.row = -1; 
    pos.col = -1;
    return pos; 
}


//这个函数修改二维数组a中所有值为key的元素值为new_val。
void modify(int n, int m, int a[][m], int key, int new_val)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == key) {
                a[i][j] = new_val;
            } 
        }
    }
} 

//输出数组长度和元素
void disp(int n, int m,int a[n][m])                 
{
    printf("Row: %d, Col: %d\n", n, m); 
    
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            printf("%5d", a[i][j]);
        }
        printf("\n"); 
    } 
}
#include <stdio.h>
#include <string.h>

#define MAX_RECORDS 100
/*#define MAX_RECORDS 100 是一个预处理指令，用于在代码中定义一个常量 
MAX_RECORDS，它的值为 100。
预处理指令是在编译之前由预处理器处理的指令，用于对代码进行文本替换。
在这个例子中，#define 指令用于创建一个常量的别名，即将 MAX_RECORDS 
定义为值 100。在代码中使用 MAX_RECORDS 时，预处理器会将其替换为实际的值 100。

常量是一个在程序执行期间不能被修改的固定值。
在编程中，常量用于存储不会改变的数据，例如固定的数值、字符串、布尔值等，它们在程序运行过程中保持不变。与之相对的是变量，变量的值可以在程序执行过程中进行修改。

常量在程序中有多种作用：

提高代码的可读性和可维护性：使用常量可以让程序更易读，并且当需要调整这些固定值时，只需要修改一处定义。
防止意外修改：将固定值定义为常量可以防止在程序执行期间无意间修改其值，确保程序的正确性。
优化编译器优化：编译器可以利用常量的特性进行优化，例如避免重复计算、替代运行时计算等。
*/
struct Product {
    char code[5];
    char name[11];
    int price;
    int quantity;
    long amount;
};

void sortRecords(struct Product records[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // 先按产品代码从大到小排序
            if (strcmp(records[j].code, records[j + 1].code) < 0) {
                /*strcmp() 函数是C语言中的字符串比较函数，它的返回值会根据两个字符串的大小关系进行不同的返回：
                若第一个字符串小于第二个字符串，则返回一个负数。
                若两个字符串相等，则返回0。
                若第一个字符串大于第二个字符串，则返回一个正数。*/
                struct Product temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
            // 若产品代码相同，则按金额从大到小排序
            else if (strcmp(records[j].code, records[j + 1].code) == 0 && records[j].amount < records[j + 1].amount) {
                struct Product temp = records[j];
                records[j] = records[j + 1];
                records[j + 1] = temp;
            }
        }
    }
}

int main() {
    struct Product records[MAX_RECORDS];
    int n;
    
    printf("请输入销售记录数量：");
    scanf("%d", &n);
    
    printf("请输入销售记录：\n");
    for (int i = 0; i < n; i++) {
        printf("销售记录 %d：\n", i + 1);
        printf("产品代码：");
        scanf("%s", records[i].code);
        printf("产品名称：");
        scanf("%s", records[i].name);
        printf("单价：");
        scanf("%d", &records[i].price);
        printf("数量：");
        scanf("%d", &records[i].quantity);
        records[i].amount = (long) records[i].price * records[i].quantity;
    }
    
    sortRecords(records, n);
    
    printf("\n按产品代码从大到小排列的销售记录：\n");
    printf("代码\t名称\t单价\t数量\t金额\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%s\t%d\t%d\t%ld\n", records[i].code, records[i].name, records[i].price, records[i].quantity, records[i].amount);
    }
    
    return 0;
}
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void reverseString(char str[]) {
    int start = 0; // 字符串起始索引
    int end = strlen(str) - 1; // 字符串结束索引

    while (start < end) {
        // 交换起始索引和结束索引对应的字符
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        // 更新起始索引和结束索引
        start++;
        end--;
    }
}


//指针
/*
void reverseString(char* str) {
    int start = 0; // 字符串起始索引
    int end = strlen(str) - 1; // 字符串结束索引

    while (start < enp['pold) {
        // 交换起始索引和结束索引对应的字符
        char temp = *(str + start);
        *(str + start) = *(str + end);
        *(str + end) = temp;

        // 更新起始索引和结束索引
        start++;
        end--;
    }
}
*/

int main() {
    char str[MAX_LENGTH];

    printf("请输入一个字符串：");
    scanf("%s", str);

    reverseString(str);

    printf("反向输出的字符串为：%s\n", str);

    return 0;
}
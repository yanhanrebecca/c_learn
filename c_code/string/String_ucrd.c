#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

// 字符串增加函数
void addString(char* str, const char* newStr) {
    strcat(str, newStr);
}

// 字符串删除函数
// void deleteString(char* str, int start, int length) {
//     memmove(str + start, str + start + length, strlen(str) - start - length + 1);
// }
// 字符串删除函数（不使用memmove）
void deleteString(char* str, int start, int length) {
    int len = strlen(str);

    // 确保起始位置和长度在有效范围内
    if (start < 0 || start >= len || length <= 0 || start + length > len)
        return;

    char* src = str + start + length;
    char* dest = str + start;

    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

// 字符串修改函数
void updateString(char* str, int start, const char* newStr) {
    //把newStr在start位置插入
    strcpy(str + start, newStr);
}

// 字符串查找函数
int findSubstring(const char* str, const char* substr) {
    int n = strlen(str);
    int m = strlen(substr);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (str[i + j] != substr[j]) {
                break;
            }
        }
        if (j == m) {
            return i; // 找到子串的起始索引
        }
    }

    return -1; // 未找到子串
}

int main() {
    char str[MAX_LENGTH];

    // 初始化原始字符串
    printf("请输入一个字符串：");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // 移除换行符

    printf("原始字符串为：%s\n", str);

    // 增加字符串
    char newStr[MAX_LENGTH];
    printf("请输入要增加的字符串：");
    fgets(newStr, sizeof(newStr), stdin);
    newStr[strcspn(newStr, "\n")] = '\0'; // 移除换行符
    addString(str, newStr);
    printf("增加后的字符串为：%s\n", str);

    // 删除字符串
    int start, length;
    printf("请输入要删除的起始位置和长度（以空格分隔）：");
    scanf("%d %d", &start, &length);
    deleteString(str, start, length);
    printf("删除后的字符串为：%s\n", str);

    // 修改字符串
    char updateStr[MAX_LENGTH];
    printf("请输入要修改的字符串：");
    scanf("%s", updateStr);
    printf("请输入要修改的起始位置：");
    scanf("%d", &start);
    updateString(str, start, updateStr);
    printf("修改后的字符串为：%s\n", str);

    // 查找子串
    char substr[MAX_LENGTH];
    printf("请输入要查找的子串：");
    scanf("%s", substr);
    int index = findSubstring(str, substr);
    if (index != -1) {
        printf("子串 \"%s\" 的起始索引为：%d\n", substr, index);
    } else {
        printf("未找到子串 \"%s\"\n", substr);
    }

    return 0;
}

/*
addString() 函数用于在字符串末尾增加另一个字符串。
deleteString() 函数用于从字符串中删除指定位置和长度的子串。
updateString() 函数用于修改字符串中指定位置的子串。
findSubstring() 函数用于在字符串中查找指定子串，并返回子串的起始索引。

在 main() 函数中，首先获取用户输入的原始字符串。然后按顺序执行增加、删除、
修改和查找子串的操作，每个操作后都打印输出最新的字符串结果。
*/
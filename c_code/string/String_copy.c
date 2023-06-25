#include <stdio.h>

#define MAX_LENGTH 100

void copyString(char s1[], const char s2[]) {
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

//指针
/*
void copyString(char *s1, const char *s2) {
    while (*s2 != '\0') {
        *s1 = *s2;
        s1++;
        s2++;
    }
    *s1 = '\0';
}
*/

int main() {
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    printf("请输入源字符串 s2：");
    scanf("%s", s2);

    copyString(s1, s2);

    printf("复制后的字符串 s1：%s\n", s1);

    return 0;
}
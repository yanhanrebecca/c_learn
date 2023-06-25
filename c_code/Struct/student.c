#include <stdio.h>

#define MAX_STUDENTS 100

// 定义学生记录的结构体
struct Student {
    int studentID;
    float score;
};

// 函数：找到成绩最低的学生记录并返回
struct Student findLowestScore(struct Student students[], int n) {
    struct Student lowest = students[0]; // 假设第一个学生记录是最低成绩的记录
    
    for (int i = 1; i < n; i++) {
        if (students[i].score < lowest.score) {
            lowest = students[i];
        }
    }
    
    return lowest;
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n;
    
    printf("请输入学生数量：");
    scanf("%d", &n);
    
    printf("请输入学生的学号和成绩：\n");
    for (int i = 0; i < n; i++) {
        printf("学生 %d：\n", i + 1);
        printf("学号：");
        scanf("%d", &students[i].studentID);
        printf("成绩：");
        scanf("%f", &students[i].score);
    }
    
    struct Student lowestScoreStudent = findLowestScore(students, n);
    
    printf("\n成绩最低的学生记录是：\n");
    printf("学号：%d\n", lowestScoreStudent.studentID);
    printf("成绩：%f\n", lowestScoreStudent.score);
    
    return 0;
}
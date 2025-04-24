#include <cstdio>

int main() {
    int T, A, B, result = 0; // T, A, B, 결과 변수 선언
    char oper; // 연산자 변수 선언
    scanf("%d", &T); // T 입력
    while (T--) { // T 만큼 반복
        scanf("%d %c %d", &A, &oper, &B); // A, 연산자, B 입력

        // 연산자에 따라 분기하여 값 할당
        if (oper == '+') result += A + B;
        else if (oper == '-') result += A - B;
        else if (oper == '*') result += A * B;
        else result += A / B;
    }

    // 결과 출력
    printf("%d", result);
}
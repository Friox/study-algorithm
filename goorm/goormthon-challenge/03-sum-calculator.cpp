#include <cstdio>

int main() {
    int T, A, B, result = 0;
    char oper;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %c %d", &A, &oper, &B);
        if (oper == '+') result += A + B;
        else if (oper == '-') result += A - B;
        else if (oper == '*') result += A * B;
        else result += A / B;
    }
    printf("%d", result);
}
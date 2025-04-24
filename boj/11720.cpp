#include <stdio.h>

int main() {
    char str[101] = { 0 };
    int a, result = 0;
    scanf("%d", &a);
    scanf("%s", str);
    for (int i = 0; i < a; i++) result += str[i] - '0';
    printf("%d", result);
}
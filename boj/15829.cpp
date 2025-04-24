#include <stdio.h>

int main() {
    long long hash = 0, temp;
    int L, r = 31, M = 1234567891, num;
    char str[51] = { 0 };
    scanf("%d", &L);
    scanf("%s", str);
    for (int i = 0; i < L; i++) {
        num = str[i] - 'a' + 1;
        temp = num;
        for (int j = 0; j < i; j++) {
            temp *= r;
            temp %= M;
        }
        hash += temp;
    }
    printf("%lld", hash % M);
}
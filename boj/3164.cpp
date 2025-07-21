#include <cstdio>

long long resolve(int y, int a, int b) {
    long long sum = 0;
    int limit = y > b ? b : y;
    if (y >= a) {
        sum += (limit - a + 1) * (y % 2 == 0 ? 1 : 0);
        a = limit + 1;
    }
    a += (a % 2 == 0 ? 0 : 1);
    b += (b % 2 == 0 ? 0 : -1);
    return sum + (a > b ? 0 : ((b - a) / 2) + 1);
}

int main() {
    long long sum = 0;
    int X1, Y1, X2, Y2;
    scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
    for (int i = Y1 + 1; i <= Y2; i++) sum += resolve(i, X1 + 1, X2);
    printf("%lld", sum);
}
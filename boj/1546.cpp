#include <stdio.h>

int main() {
    int a, b = 0, N, M = -1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (a > M) M = a;
        b += a;
    }
    printf("%lf", ((double)b / N) * (100.0 / M));
}
#include <stdio.h>

int main() {
    int N, K, coin[10] = { 0 }, cnt = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &coin[i]);
    for (int i = N - 1; i >= 0; i--) {
        if (K == 0) break;
        cnt += (K / coin[i]);
        K %= coin[i];
    }
    printf("%d", cnt);
}
#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int main() {
    int N, num[1000001] = { 0 };
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        num[i] = __INT_MAX__;
        if (i % 3 == 0) num[i] = MIN(num[i / 3] + 1, num[i]);
        if (i % 2 == 0) num[i] = MIN(num[i / 2] + 1, num[i]);
        num[i] = MIN(num[i - 1] + 1, num[i]);
        printf("%d: %d\n", i, num[i]);
    }
    printf("%d", num[N]);
}
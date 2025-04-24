#include <stdio.h>

int main() {
    int M, N, sum = 0, min = 0, sq, i = 1;
    scanf("%d %d", &M, &N);
    while ((sq = i * i) <= N) {
        if (sq >= M) {
            sum += sq;
            if (min == 0) min = sq;
        }
        ++i;
    }
    if (sum == 0) printf("-1");
    else printf("%d\n%d", sum, min);
}
#include <stdio.h>

int main() {
    int N, tmp, twoCnt = 0, fiveCnt = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        tmp = i;
        while (!(tmp % 5)) {
            fiveCnt++;
            tmp /= 5;
        }
        while (!(tmp % 2)) {
            twoCnt++;
            tmp /= 2;
        }
    }
    printf("%d", (twoCnt < fiveCnt ? twoCnt : fiveCnt));
}
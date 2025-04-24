#include <stdio.h>

int main() {
    int N, num, cnt[2001] = { 0 }, allCnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        cnt[num + 1001]++;
    }
    for (int i = 0; i <= 2001; i++) {
        if (cnt[i] != 0) {
            if (allCnt != 0) printf("\n");
            printf("%d", i - 1001);
            allCnt += cnt[i];
            if (allCnt == N) break;
        }
    }
}
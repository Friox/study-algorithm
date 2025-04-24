#include <stdio.h>

int returnIndex(int num) { return num + 1000001; }

int main() {
    int N, num, cnt[2000001] = { 0 }, allCnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        cnt[returnIndex(num)]++;
    }
    for (int i = 0; i <= 2000001; i++) {
        if (cnt[i] != 0) {
            if (allCnt != 0) printf("\n");
            printf("%d", i - 1000001);
            allCnt += cnt[i];
            if (allCnt == N) break;
        }
    }
}
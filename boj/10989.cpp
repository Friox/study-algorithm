#include <stdio.h>

int main() {
    int cnt[10001] = { 0 }, maxNum = 0, N, a;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        cnt[a]++;
        maxNum = (a > maxNum ? a : maxNum);
    }
    for (int i = 1; i <= maxNum; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            printf("%d", i);
            if (!(i == maxNum && j == cnt[i] - 1)) printf("\n");
        }
    }
}
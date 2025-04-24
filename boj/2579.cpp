#include <stdio.h>
int max(int a, int b) { return a > b ? a : b; }
int main() {
    int N, DP[301], stairs[301] = { 0 };
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) scanf("%d", &stairs[i]);
    DP[1] = stairs[1];
    DP[2] = stairs[1] + stairs[2];
    DP[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
    for (int i = 4; i <= N; i++) DP[i] = max(DP[i - 2] + stairs[i], DP[i - 3] + stairs[i - 1] + stairs[i]);
    printf("%d", DP[N]);
}
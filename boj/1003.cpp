#include <stdio.h>

int main() {
    int T, N;
    int dp[41] = { 0, 1, 1 };
    for (int i = 3; i < 41; i++) dp[i] = dp[i - 1] + dp[i - 2];
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &N);
        if(N == 0) printf("%d %d", 1, 0);
        else if (N == 1) printf("%d %d", 0, 1);
        else printf("%d %d", dp[N - 1], dp[N]);
        if (i != T - 1) printf("\n");
    }
}
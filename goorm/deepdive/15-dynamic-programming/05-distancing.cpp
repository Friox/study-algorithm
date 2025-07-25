#include <cstdio>

const int MOD = 100000007;

int main() {
    int n;
    scanf("%d", &n);
    long long dp[2][5] = { 0 };
    for(int i = 0; i < 5; i++) dp[1][i] = 1;
    for(int i = 2; i <= n; i++) {
        int cur = i % 2, prev = 1 - cur;
        dp[cur][0] = (dp[prev][0] + dp[prev][1] + dp[prev][2] + dp[prev][3] + dp[prev][4]) % MOD;
        dp[cur][1] = (dp[prev][0] + dp[prev][2] + dp[prev][3]) % MOD;
        dp[cur][2] = (dp[prev][0] + dp[prev][1] + dp[prev][3] + dp[prev][4]) % MOD;
        dp[cur][3] = (dp[prev][0] + dp[prev][1] + dp[prev][2]) % MOD;
        dp[cur][4] = (dp[prev][0] + dp[prev][2]) % MOD;
    }
    int last = n % 2;
    long long ans = 0;
    for(int i = 0; i < 5; i++) ans = (ans + dp[last][i]) % MOD;
    printf("%lld", ans);
}
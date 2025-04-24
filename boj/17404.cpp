#include <ios>
#include <algorithm>

#define MAX 1000001

int main() {
    int cost[1001][3] = { 0 };
    int r, g, b, n, res = MAX;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &r, &g, &b);
        cost[i][0] = r;
        cost[i][1] = g;
        cost[i][2] = b;
    }
    for (int s = 0; s <= 2; s++) {
        int dp[1001][3];
        for (int j = 0; j <= 2; j++) {
            if (j == s) dp[1][s] = cost[1][s];
            else dp[1][j] = MAX;
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = std::min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
        }
        for (int j = 0; j <= 2; j++) {
            if (j != s) res = std::min(res, dp[n][j]);
        }
    }
    printf("%d", res);
}
#include <stdio.h>
int main() {
    int n, dp[1001] = { 0, 1, 2, 0 };
    scanf("%d", &n);
    for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + 1 < dp[i - 3] + 1 ? dp[i - 1] + 1 : dp[i - 3] + 1);
	if (dp[n] % 2) printf("SK");
	else printf("CY");
}
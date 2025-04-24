#include <stdio.h>
int main() {
	int dp[1001] = { 0, 1, 3 }, n;
	scanf("%d", &n);
	for (int i = 3; i <= n; i++) dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % 10007;
	printf("%d", dp[n]);
}
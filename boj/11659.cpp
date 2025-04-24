#include <stdio.h>

int main() {
	int n, m, x, y, num, dp[100001] = { 0 };
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
		dp[i] = dp[i - 1] + num;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		printf("%d\n", dp[y] - dp[x - 1]);
	}
}
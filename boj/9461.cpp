#include <stdio.h>

int main() {
	int T, N;
	long long dp[101] = { 0, 1, 1, 1, 0 };
	for (int i = 4; i <= 100; i++) dp[i] = dp[i - 3] + dp[i - 2];
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		printf("%lld\n", dp[N]);
	}
}
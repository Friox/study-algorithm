#include <stdio.h>
#include <queue>
int main() {
	long long dp[68] = {1, 1, 2, 4, 0};
	int t, n;

	long long target = 8;
	std::queue<long long> q;
	q.push(1); q.push(1); q.push(2); q.push(4);
	for (int i = 4; i < 68; ++i) {
		dp[i] = target;
		target -= q.front();
		target += dp[i];
		q.pop();
		q.push(dp[i]);
	}

	// for (int i = 4; i < 68; ++i) dp[i] = dp[i - 4] + dp[i - 3] + dp[i - 2] + dp[i - 1];
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}
}
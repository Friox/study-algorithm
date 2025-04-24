#include <stdio.h>
#include <vector>
int main() {
	int n, max = 0;
	scanf("%d", &n);
	std::vector<int> v(n + 1), dp(n + 1, 1);
	for (int i = 1; i <= n; ++i) scanf("%d", &v[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (v[i] > v[j]) {
				dp[i] = (dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1);
				if (dp[i] > max) max = dp[i];
			}
		}
	}
	printf("%d", max);
}
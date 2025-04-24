#include <ios>
#include <vector>
int main() {
	int n, k, x, sum = 0, mS = 0;
	scanf("%d %d %d", &n, &k, &x);
	std::vector<std::pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &v[i].first, &v[i].second);
		sum += v[i].first;
	}
	std::vector<std::vector<int>> dp(sum + 1, std::vector<int>(k + 1));
	dp[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		for (int j = k; j > 0; --j) {
			for (int kk = sum; kk >= v[i].first; --kk) {
				dp[kk][j] |= dp[kk - v[i].first][j - 1];
			}
		}
	}
	for (int i = 0; i <= sum; ++i) {
		if (dp[i][k]) mS = std::max(mS, i * (x * k - i));
	}
	printf("%d", mS);
}
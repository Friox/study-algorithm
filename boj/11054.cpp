#include <ios>
#include <utility>
int main() {
	int n, arr[1000] = { 0 };
	std::pair<int, int> dp[1000] = { {0, 0} };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		dp[i].first = 1;
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i].first < dp[j].first + 1) {
				dp[i].first = dp[j].first + 1;
			}
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		dp[i].second = 1;
		for (int j = n - 1; j >= i; j--) {
			if (arr[j] < arr[i] && dp[i].second < dp[j].second + 1) {
				dp[i].second = dp[j].second + 1;
			}
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		int temp = dp[i].first + dp[i].second - 1;
		if (result < temp) result = temp;
	}
	printf("%d", result);
}
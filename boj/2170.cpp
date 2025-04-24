#include <stdio.h>
#include <utility>
#include <algorithm>
typedef std::pair<int, int> line;
int main() {
	int n, res = 0, start = -1000000001, end = -1000000001;
	line arr[1000000];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &arr[i].first, &arr[i].second);
	std::sort(arr, arr + n);
	for (int i = 0; i < n; ++i) {
		line tmp = arr[i];
		if (start <= tmp.first && tmp.second <= end) continue;
		res += tmp.second - tmp.first;
		if (tmp.first < end) res -= (end - tmp.first);
		start = tmp.first;
		end = tmp.second;
	}
	printf("%d", res);
}
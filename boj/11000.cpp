#include <functional>
#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <vector>
int main() {
	int n, a, b;
	std::pair<int, int> arr[200000];
	std::priority_queue<int, std::vector<int>, std::greater<int>> q;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d %d", &arr[i].first, &arr[i].second);
	std::sort(arr, arr + n);
	q.push(arr[0].second);
	for (int i = 1; i < n; ++i) {
		q.push(arr[i].second);
		if (q.top() <= arr[i].first) q.pop();
	}
	printf("%ld", q.size());
}
#include <stdio.h>
#include <algorithm>
int arr[100000];
int main() {
	int n, m, s = 0, e = 0, res = 2147483647;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	while (s < n && e < n) {
		int tmp = arr[e] - arr[s];
		if (tmp < m) ++e;
		else {
			if (tmp < res) res = tmp;
			++s;
		}
	}
	printf("%d", res);
}
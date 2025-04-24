#include <stdio.h>
#include <algorithm>
int arr[200000];
int main() {
	int n, c, s = 1, e, m, r = 0, cnt, tmp;
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	e = arr[n - 1] - arr[0];
	while (s <= e) {
		m = (s + e) / 2;
		cnt = 1;
		tmp = arr[0];
		for (int i = 1; i < n; ++i) {
			if (arr[i] - tmp >= m) {
				++cnt;
				tmp = arr[i];
			}
		}
		if (cnt >= c) {
			r = (r > m ? r : m);
			s = m + 1;
		} else e = m - 1;
	}
	printf("%d", r);
}
#include <stdio.h>
#include <queue>
int main() {
	std::queue<int> q;
	int *arr, n, k, s = 0, e = 0, cnt = 0, r = -1, tmp;
	scanf("%d %d", &n, &k);
	arr = new int[n];
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	for (;e < n;++e) {
		if (arr[e] == 1) {
			if (cnt++) q.push(e);
			if (cnt == k) {
				tmp = e - s + 1;
				if (r == -1) r = tmp;
				else if (tmp < r) r = tmp;
				s = q.front();
				q.pop();
				--cnt;
			}
		}
	}
	printf("%d", r);
}
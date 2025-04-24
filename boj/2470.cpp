#include <stdio.h>
#include <algorithm>
int main() {
	int n, a[100000] = { 0 }, a1, a2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	std::sort(a, a + n);
	int s = 0, e = n - 1, m = 2147483647;
	while (s < e) {
		int sum = a[s] + a[e];
		if (m > std::abs(sum)) {
			m = std::abs(sum);
			a1 = s; a2 = e;
			if (sum == 0) break;
		}
		if (sum < 0) s++;
		else e--;
	}
	printf("%d %d", a[a1], a[a2]);
}
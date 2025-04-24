#include <stdio.h>
int main() {
	int n, k, r = 0;
	scanf("%d %d", &n, &k);
	if (n > k) {
		for (;;++r) {
			int cnt = 0, tmp = n;
			while (tmp) {
				if (tmp % 2) ++cnt;
				tmp /= 2;
			}
			if (cnt <= k) break;
			++n;
		}
	}
	printf("%d", r);
}
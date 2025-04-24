#include <stdio.h>

int main() {
	int n, h[100000], limit, cnt = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &h[i]);
	limit = h[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		if (h[i] > limit) {
			cnt++;
			limit = h[i];
		}
	}
	printf("%d", cnt);
}
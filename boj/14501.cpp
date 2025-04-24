#include <stdio.h>
int main() {
	int n, a[17] = { 0 }, b[17] = { 0 }, c[17] = { 0 };
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%d %d", &a[i], &b[i]);
	for (int i = n; i > 0; --i) {
		if (i + a[i] > n + 1) c[i] = c[i + 1];
		else c[i] = c[i + 1] > c[i + a[i]] + b[i] ? c[i + 1] : c[i + a[i]] + b[i];
	}
	printf("%d", c[1]);
}
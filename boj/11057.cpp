#include <stdio.h>
int main() {
	int n, a[1001][10], r = 0;
	scanf("%d", &n);
	for (int i = 0; i < 10; ++i) a[1][i] = 1;
	for (int i = 2; i <= n; ++i) {
		a[i][0] = 1;
		for (int j = 1; j < 10; ++j) a[i][j] = (a[i - 1][j] + a[i][j - 1]) % 10007;
	}
	for (int i = 0; i < 10; ++i) r += a[n][i];
	printf("%d", r % 10007);
}
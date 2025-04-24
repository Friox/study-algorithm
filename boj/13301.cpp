#include <stdio.h>
int main() {
	long long arr[2][80] = {{1, 1, 0}, {4, 6, 0}};
	int n;
	scanf("%d", &n);
	for (int i = 2; i < n; ++i) {
		arr[0][i] = arr[0][i - 1] + arr[0][i - 2];
		arr[1][i] = arr[1][i - 1] + arr[0][i] * 2;
	}
	printf("%lld", arr[1][n - 1]);
}
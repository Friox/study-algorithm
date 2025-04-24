#include <stdio.h>
int main() {
	int f[1500000] = { 0, 1, 0 };
	long long n;
	scanf("%lld", &n);
	n %= 1500000;
	for (int i = 2; i <= n; ++i) f[i] = (f[i - 1] + f[i - 2]) % 1000000;
	printf("%d", f[n]);
}
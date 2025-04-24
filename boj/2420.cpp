#include <stdio.h>

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	printf("%lld", (n - m < 0 ? -(n - m) : n - m));
}
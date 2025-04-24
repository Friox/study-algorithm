#include <stdio.h>

int main() {
	unsigned int a;
	long long n = 1;
	scanf("%d", &a);
	while ((n * (n + 1)) / 2 <= a) n += 1;
	printf("%lld", n - 1);
}
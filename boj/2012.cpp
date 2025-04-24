#include <stdio.h>
#include <algorithm>

int s[500001] = { 0 };

int main() {
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
	std::sort(s + 1, s + n + 1);
	for (int i = 1; i <= n; i++) sum += abs(s[i] - i);
	printf("%lld", sum);
}
#include <stdio.h>
int main() {
	int n, m, a;
	long long mod[1001] = { 0 }, sum = 0, cnt = 0;
	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%d", &a);
		sum += a;
		++mod[sum % m];
	}
	for (int i = 0; i <= 1000; i++) {
		if (mod[i] > 1) {
			cnt += mod[i] * (mod[i] - 1) / 2;
		}
	}
	printf("%lld", mod[0] + cnt);
}
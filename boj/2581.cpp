#include <stdio.h>
#include <math.h>

int main() {
	bool nPrime[10001] = { 1, 1, 0 };
	int m, n, sum = 0, min = 10001;
	scanf("%d %d", &m, &n);
	int LIMIT = sqrt(n);
	for (int i = 2; i <= LIMIT; i++) {
		for (int j = i * 2; j <= 10000; j += i) {
			nPrime[j] = 1;
		}
	}
	for (int i = m; i <= n; i++) {
		if (!nPrime[i]) {
			sum += i;
			min = (i < min ? i : min);
		}
	}
	if (sum) printf("%d\n%d", sum, min);
	else printf("-1");
}
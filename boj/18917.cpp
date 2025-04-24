#include <stdio.h>

int main() {
	int m, q, a, xorSum = 0;
	long long sum = 0;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &q);
		if (q < 3) {
			scanf("%d", &a);
			if (q == 1) sum += a;
			else sum -= a;
			xorSum ^= a;
		} else {
			if (q == 3) printf("%lld\n", sum);
			else printf("%d\n", xorSum);
		}
	} 
}
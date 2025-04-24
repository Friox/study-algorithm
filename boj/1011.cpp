#include <stdio.h>

int main() {
	long long t, x, y, distance, cnt;
	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &x, &y);
		distance = y - x;
		cnt = 0;
		while (distance > cnt * (cnt + 1)) cnt++;
		printf("%lld\n", cnt * 2 - (distance <= cnt * cnt ? 1 : 0));
	}
}
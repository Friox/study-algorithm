#include <stdio.h>

int main() {
	int cnt = 3;
	long long sum = 0, i;
	while(cnt--) {
		scanf("%lld", &i);
		sum += i;
	}
	printf("%lld", sum);
}
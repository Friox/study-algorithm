#include <stdio.h>
int main() {
	int num = 5, inc = 7, n;
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		num += inc;
		inc += 3;
		num %= 45678;
		// inc %= 45678;
	}
	printf("%d", num);
}
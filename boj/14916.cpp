#include <stdio.h>
int main() {
	int n, five, one;
	scanf("%d", &n);
	five = n / 5;
	one = n % 5;
	if (!five) {
		if (one % 2) printf("-1");
		else printf("%d", one / 2);
	} else {
		if (one % 2) {
			--five;
			if ((one + 5) % 2) printf("-1");
			else printf("%d", five + (one + 5) / 2);
		} else printf("%d", five + one / 2);
	}
}
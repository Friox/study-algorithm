#include <stdio.h>

int main() {
	int sum = 0, n = 4, t;
	while (n--) {
		scanf("%d", &t);
		sum += t;
	}
	printf("%d\n%d", sum / 60, sum % 60);
}
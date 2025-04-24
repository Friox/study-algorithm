#include <stdio.h>

int main() {
	int sum = 0, n = 5, t;
	while (n--) {
		scanf("%d", &t);
		sum += t;
	}
	printf("%d", sum);
}
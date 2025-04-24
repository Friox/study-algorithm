#include <stdio.h>

int main() {
	int n, num[6] = { 0 }, sum = 0, max = 0;
	for (int i = 0; i < 3; i++) {
		scanf("%d", &n);
		num[n - 1]++;
	}
	for (int i = 0; i < 6; i++) {
		if (num[i] == 3) {
			printf("%d", 10000 + (i + 1) * 1000);
			return 0;
		} else if (num[i] == 2) {
			printf("%d", 1000 + (i + 1) * 100);
			return 0;
		} else if (num[i] == 1) {
			max = (i + 1) > max ? (i + 1) : max;
		}
	}
	printf("%d", max * 100);
}
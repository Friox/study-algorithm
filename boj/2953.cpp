#include <stdio.h>
int main() {
	int n, idx, sum, max = 0;
	for (int i = 1; i <= 5; i++) {
		sum = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &n);
			sum += n;
		}
		if (sum > max) {
			idx = i;
			max = sum;
		}
	}
	printf("%d %d", idx, max);
}
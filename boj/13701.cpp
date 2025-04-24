#include <stdio.h>
int arr[1048576], n, idx, bit;
int main() {
	while (scanf("%d", &n) != EOF) {
		idx = n / 32;
		bit = n % 32;
		if (!(arr[idx] & (1 << bit))) {
			arr[idx] += (1 << bit);
			printf("%d ", n);
		}
	}
}
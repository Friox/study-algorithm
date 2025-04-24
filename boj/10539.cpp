#include <stdio.h>

int main() {
	int n, a[100], sum = 0, temp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		temp = a[i] * (i + 1) - sum;
		if (i != 0) printf(" ");
		printf("%d", temp);
		sum += temp;
	}
}
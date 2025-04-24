#include <stdio.h>

int main() {
	int n, na[1001] = {1, 1, 0};
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) na[i] = (na[i - 1] + na[i - 2]) % 10007;
	printf("%d", na[n]);
}
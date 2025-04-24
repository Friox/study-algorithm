#include <stdio.h>

int main() {
	int n, arr[100001] = { 0, 3, 7, 17, 0 };
	scanf("%d", &n);
	for (int i = 4; i <= n; i++) arr[i] = (arr[i - 1] * 2 + arr[i - 2]) % 9901;
	printf("%d", arr[n]);
}
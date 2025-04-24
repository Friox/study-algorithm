#include <stdio.h>
int main() {
	int a[6] = { 500, 100, 50, 10, 5, 1 };
	int n, cnt = 0;
	scanf("%d", &n);
	n = 1000 - n;
	for (int i = 0; i < 6; i++) {
		cnt += n / a[i];
		n %= a[i];
	}
	printf("%d", cnt);
}
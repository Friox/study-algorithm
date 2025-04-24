#include <stdio.h>

int main() {
	int n, a, b, cnt;
	scanf("%d %d %d", &n, &a, &b);
	cnt = (a / 2) + b;
	printf("%d", cnt > n ? n : cnt);
}
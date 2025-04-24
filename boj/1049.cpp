#include <stdio.h>

int main() {
	int n, m, a = 1001, b = 1001, ta, tb, cost = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &ta, &tb);
		a = (ta < a ? ta : a);
		b = (tb < b ? tb : b);
	}
	cost += (n / 6) * (b * 6 < a ? b * 6 : a);
	n %= 6;
	cost += (b * n < a ? b * n : a);
	printf("%d", cost);
}
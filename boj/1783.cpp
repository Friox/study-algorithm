#include <stdio.h>
int main() {
	int n, m, o[7] = { 1, 2, 3, 4, 4, 4, 5 };
	scanf("%d %d", &n, &m);
	if (n == 1) printf("1");
	else if (n == 2) {
		int t = (m - 1) / 2;
		printf("%d", (t > 3 ? 3 : t) + 1);
	} else {
		int idx = (m > 7 ? 6 : m - 1);
		printf("%d", o[idx] + (m - 7 < 0 ? 0 : m - 7));
	}
}
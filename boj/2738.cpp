#include <stdio.h>

int main() {
	int a[100][100] = { 0 }, n, m, num;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &num);
			printf("%d%c", a[i][j] + num, (j == m - 1 ? '\n' : ' '));
		}
	}
}
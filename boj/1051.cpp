#include <stdio.h>
int arr[50][50];
int main() {
	int n, m, res = 1;
	char str[50][51];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) scanf(" %s", str[i]);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			arr[i][j] = str[i][j] - '0';
		}
	}
	for (int i = 1; i <= n && i <= m; ++i) {
		for (int j = 0; j + i < n; ++j) {
			for (int k = 0; k + i < m; ++k) {
				if (arr[j][k] == arr[j][k + i] && arr[j][k] == arr[j + i][k] && arr[j][k] == arr[j + i][k + i]) {
					if (i + 1 > res) res = i + 1;
				}
			}
		}
	}
	printf("%d", res * res);
}
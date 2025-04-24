#include <ios>

int main() {
    int arr[2001], n, m, s, e;
    bool pal[2001][2001] = { 0, };
    scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (int i = 1; i <= n - 1; i++) if (arr[i] == arr[i + 1]) pal[i][i + 1] = 1;
	for (int i = 1; i <= n; i++) pal[i][i] = 1;

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 2; j <= n; j++) {
			if (arr[i] == arr[j] && pal[i + 1][j - 1]) pal[i][j] = 1;
		}
	}
    
    scanf("%d", &m);

	for (int i = 0; i < m; i++) {
        scanf("%d %d", &s, &e);
        printf("%d\n", pal[s][e]);
	}
}
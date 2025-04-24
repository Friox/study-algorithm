#include <ios>
#include <algorithm>

int main() {
	bool map[100][100] = { 0 };
	int n, d, cnt = 0, r[100] = { 0 };
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		map[i][d - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d%c", map[i][j], (j == n - 1 ? '\n' : ' '));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (map[i][j] + map[j][i] == 2) {
				if (i == j) r[cnt++] = j + 1;
				else {
					r[cnt++] = i + 1;
					r[cnt++] = j + 1;
				}
			}
		}
	}
	std::sort(r, r + cnt);
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) printf("%d\n", r[i]);
}
#include <stdio.h>

int main() {
	bool map[500][500] = { 0 };
	int h, w, n, cnt = 0;
	scanf("%d %d", &h, &w);
	for (int i = 0; i < w; i++) {
		scanf("%d", &n);
		for (int j = h - 1; j >= h - n; j--) {
			map[j][i] = 1;
			++cnt;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (map[i][j]) break;
			else {
				map[i][j] = 1;
				++cnt;
			}
		}
		for (int j = w - 1; j >= 0; j--) {
			if (map[i][j]) break;
			else {
				map[i][j] = 1;
				++cnt;
			}
		}
	}
	printf("%d", h * w - cnt);
}
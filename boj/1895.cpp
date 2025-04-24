#include <stdio.h>
#include <algorithm>

int main() {
	int arr[40][40], filter[9], r, c, t, cnt = 0;
	scanf("%d %d", &r, &c);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) scanf("%d", &arr[i][j]);
	}
	scanf("%d", &t);
	int **result = new int*[r - 2];
	for (int i = 0; i < r - 2; i++) result[i] = new int[c - 2];
	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {
			for (int k = i, x = 0; k < i + 3; k++) {
				for (int l = j; l < j + 3; l++, x++) {
					filter[x] = arr[k][l];
				}
			}
			std::sort(filter, filter + 9);
			result[i][j] = filter[4];
		}
	}
	for (int i = 0; i < r - 2; i++) {
		for (int j = 0; j < c - 2; j++) {
			if (result[i][j] >= t) cnt++;
		}
	}
	printf("%d", cnt);
}
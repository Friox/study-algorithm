#include <stdio.h>

bool visible(long long ax, int ay, int bx, int by, int cx, int cy) {
	return ((bx - ax) * (cy - ay) - (by - ay) * (cx - ax)) < 0;
}

int main() {
	int n, arr[50], maxHeight, maxCnt = 0, cnt;
	scanf("%d", &n);
	bool flag;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		cnt = 0;
		if (i - 1 >= 0) cnt++;
		for (int j = i - 2; j >= 0; j--) {
			flag = true;
			for (int k = i - 1; k >= j + 1; k--) {
				if (!visible(j, arr[j], i, arr[i], k, arr[k])) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		if (i + 1 < n) cnt++;
		for (int j = i + 2; j < n; j++) {
			flag = true;
			for (int k = i + 1; k < j; k++) {
				if (!visible(i, arr[i], j, arr[j], k, arr[k])) {
					flag = false;
					break;
				}
			}
			if (flag) cnt++;
		}
		maxCnt = (cnt > maxCnt ? cnt : maxCnt);
	}
	printf("%d", maxCnt);
}
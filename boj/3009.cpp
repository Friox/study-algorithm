#include <stdio.h>

int main() {
	int arrx[1001] = { 0 };
	int arry[1001] = { 0 };
	for (int i = 0; i < 3; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		arrx[x]++; arry[y]++;
	}
	for (int i = 0; i < 1001; i++) {
		if (arrx[i] == 1) {
			printf("%d", i);
			break;
		}
	}
	for (int i = 0; i < 1001; i++) {
		if (arry[i] == 1) {
			printf(" %d", i);
			break;
		}
	}
}
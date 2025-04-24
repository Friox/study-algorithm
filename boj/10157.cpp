#include <iostream>
int nowY = -1, nowX, n, k;
bool fin() {
	if (n == k) { printf("%d %d", nowX + 1, nowY + 1); return 1; }
	return 0;
}
int main() {
	int c, r;
	scanf("%d %d %d", &c, &r, &k);
	if (k > c * r) { printf("0"); return 0; }
	while (1) {
		for (int i = 0; i < r; ++i) { ++nowY; ++n; if (fin()) return 0; } --c;
		for (int i = 0; i < c; ++i) { ++nowX; ++n; if (fin()) return 0; } --r;
		for (int i = 0; i < r; ++i) { --nowY; ++n; if (fin()) return 0; } --c;
		for (int i = 0; i < c; ++i) { --nowX; ++n; if (fin()) return 0; } --r;
	}
}
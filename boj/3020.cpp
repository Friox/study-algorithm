#include <stdio.h>
int main() {
	int t[500001] = {0}, b[500001] = {0}, n, h, a;
	scanf("%d %d", &n, &h);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);
		if (i % 2 == 0)
			++b[a];
		else
			++t[h - a + 1];
	}
	for (int i = 1; i <= h; i++) {
		t[i] += t[i - 1];
		b[h - i] += b[h - i + 1];
	}
	int r = 2147483647, cnt = 0;
	for (int i = 1; i <= h; i++) {
		if (t[i] + b[i] < r) {
			r = t[i] + b[i];
			cnt = 1;
		} else if (t[i] + b[i] == r)
			cnt++;
	}
	printf("%d %d", r, cnt);
}
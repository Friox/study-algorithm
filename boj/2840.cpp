#include <stdio.h>

int main() {
	bool check[26] = { 0 }, flag = false;
	char circle[25], c;
	int n, k, s, pin = 0;
	for (int i = 0; i < 25; i++) circle[i] = '?';
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %c", &s, &c);
		for (int j = 0; j < s; j++) pin = ++pin % n;
		if (circle[pin] != '?') {
			if (circle[pin] == c) continue;
			flag = true;
			break;
		} else {
			if (check[c - 'A']) {
				flag = true;
				break;
			} else {
				circle[pin] = c;
				check[c - 'A'] = true;
			}
		}
	}
	if (flag) {
		printf("!");
	} else {
		for (int i = 0; i < n; i++) {
			printf("%c", circle[pin]);
			pin = (--pin < 0 ? n - 1 : pin);
		}
	}
}
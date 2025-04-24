#include <stdio.h>
int main() {
	int t = 3;
	char c[5] = {'D', 'C', 'B', 'A', 'E'};
	while (t--) {
		int a = 0, n;
		for (int i = 0; i < 4; i++) {
			scanf("%d", &n);
			a += n;
		}
		printf("%c\n", c[a]);
	}
}
#include <stdio.h>
int main() {
	int tc, c, v;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &c, &v);
		printf("You get %d piece(s) and your dad gets %d piece(s).\n", c / v, c % v);
	}
}
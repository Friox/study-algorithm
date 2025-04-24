#include <stdio.h>

int main() {
	int n, c = 0, k = 0;
	scanf("%d", &n);
	getchar();
	while (n--) (getchar() == 'C' ? c++ : k++);
	printf("%d", (c / (k + 1)) + (c % (k + 1) == 0 ? 0 : 1));
}
#include <stdio.h>
int main() {
    int a[6] = {1, 1, 2, 2, 2, 8}, b;
    for (int i = 0; i < 6; i++) {
		scanf("%d", &b);
		printf("%d ", a[i] - b);
	}
}
#include <stdio.h>

int main() {
	int num;
	scanf("%d", &num);
	for (int i = 2; i <= num; i++) {
		while (num % i == 0) {
			num /= i;
			printf("%d\n", i);
		}
	}
}
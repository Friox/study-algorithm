#include <stdio.h>

int main() {
	short n = 0;
	char input[21] = { 0 };
	scanf("%s", input);
	for (short i = 0; i < 20; i++) {
		if (input[i] == 0) break;
		if (input[i] >= 'a' && input[i] <= 'z') n += input[i] - 'a' + 1;
		else n += input[i] - 38;
	}
	if (n != 2 && n % 2 == 0) printf("It is not a prime word.");
	else {
		for (int i = 3; i < n; i++) {
			if (n % i == 0) {
				printf("It is not a prime word.");
				return 0;
			}
		}
		printf("It is a prime word.");
	}
}
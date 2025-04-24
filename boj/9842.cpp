#include <stdio.h>
int main() {
	int cnt = 0, n;
	bool arr[1048577] = { 0, 1, 0 };
	for (int i = 2; i <= 1024; ++i) {
		if (!arr[i]) {
			for (int j = i * 2; j <= 1048576; j += i) arr[j] = 1;
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= 1048576; ++i) {
		if (!arr[i]) {
			if (++cnt == n) {
				printf("%d", i);
				break;
			}
		}
	}
}
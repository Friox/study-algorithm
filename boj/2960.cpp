#include <stdio.h>

int main() {
	bool arr[1001] = { 0 };
	int n, k, cnt = 0;
	scanf("%d %d", &n, &k);
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {
			for (int j = i; j <= n; j += i) {
				if (!arr[j]) {
					if (++cnt == k) {
						printf("%d", j);
						return 0;
					}
					arr[j] = true;
				}
			}
		}
	}
}
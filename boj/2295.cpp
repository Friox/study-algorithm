#include <stdio.h>
#include <algorithm>

int main() {
	int u[1000], uu[1000000], n, index = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &u[i]);
	std::sort(u, u + n);
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			uu[index++] = u[i] + u[j];
		}
	}
	std::sort(uu, uu + index);
	for (int i = n - 1; i >= 1; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (std::binary_search(uu, uu + index, u[i] - u[j])) {
				printf("%d", u[i]);
				return 0;
			}
		}
	}
}
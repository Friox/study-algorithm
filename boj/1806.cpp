#include <stdio.h>

int main() {
	bool flag = true;
	int n, s, num[100000], start = 0, end = 0, sum = 0, length = 100000;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		sum += num[i];
		end++;
		while (sum >= s && start <= end) {
			flag = false;
			length = (length > (end - start) ? (end - start) : length);
			sum -= num[start++];
		}
	}
	printf("%d", (flag ? 0 : length));
}
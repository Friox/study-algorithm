#include <functional>
#include <stdio.h>
#include <algorithm>

int main() {
	int n, arr[100000], maxDay = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	std::sort(arr, arr + n, std::greater<>());
	for (int i = 0; i < n; i++) {
		if (i + arr[i] > maxDay) maxDay = i + arr[i];
	}
	printf("%d", maxDay + 2);
}
#include <stdio.h>
#include <algorithm>
int main() {
	int n, k, arr[10000], sum = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (int i = 0; i < n - 1; ++i) arr[i] = arr[i + 1] - arr[i];
	std::sort(arr, arr + n - 1);
	for (int i = 0; i < n - k; ++i) sum += arr[i];
	printf("%d", sum);
}
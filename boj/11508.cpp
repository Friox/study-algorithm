#include <stdio.h>
#include <algorithm>

int arr[100000] = { 0 };

int main() {
	int n;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (int i = n - 1; i >= 0; i--) {
		if (i < (n % 3) || i % 3 != (n % 3)) sum += arr[i];
	}
	printf("%lld", sum);
}
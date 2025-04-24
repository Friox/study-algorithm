#include <stdio.h>
#include <algorithm>

int main() {
	int n, arr[1000000];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	std::sort(arr, arr + n);
	for (int i = n - 3; i >= 0; --i) {
		if (arr[i + 2] < arr[i + 1] + arr[i]) {
			printf("%d", arr[i + 2] + arr[i + 1] + arr[i]);
			break;
		}
		if (!i) printf("-1");
	}
}
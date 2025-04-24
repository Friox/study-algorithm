#include <stdio.h>

int main() {
	int arr[6], val;
	for (int i = 0; i < 6; i++) scanf("%d", &arr[i]);
	val = (arr[4] - arr[0]) * (arr[3] - arr[1]) - (arr[5] - arr[1]) * (arr[2] - arr[0]);
	printf("%d", (val != 0 ? val > 0 ? -1 : 1 : 0));
}
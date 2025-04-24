#include <stdio.h>
struct con { int aCount, bCount; };
int main() {
	con arr[46] = { 0 };
	int n;
	arr[0].aCount = 1; arr[0].bCount = 0;
	arr[1].aCount = 0; arr[1].bCount = 1;
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		arr[i].aCount = arr[i - 1].aCount + arr[i - 2].aCount;
		arr[i].bCount = arr[i - 1].bCount + arr[i - 2].bCount;
	}
	printf("%d %d", arr[n].aCount, arr[n].bCount);
}
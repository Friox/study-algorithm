#include <stdio.h>

int main() {
	bool flag;
	int arr[5], ans[5] = {1, 2, 3, 4, 5}, temp;
	for (int i = 0; i < 5; i++) scanf("%d", &arr[i]);
	while (1) {
		for (int i = 0; i < 4; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				for (int j = 0; j < 5; j++) {
					printf("%d%c", arr[j], j == 4 ? '\n' : ' ');
				}
			}
		}
		flag = true;
		for (int i = 0; i < 5; i++) {
			if (arr[i] != ans[i]) {
				flag = false;
				break;
			}
		}
		if (flag) break;
	}
}
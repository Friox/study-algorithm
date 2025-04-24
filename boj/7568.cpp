#include <stdio.h>

struct person { int x, y; };

int main() {
	person mPerson[50] = { 0 };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d %d", &mPerson[i].x, &mPerson[i].y);
	for (int i = 0; i < n; i++) {
		int k = 1;
		for (int j = 0; j < n; j++) {
			if (mPerson[i].x < mPerson[j].x && mPerson[i].y < mPerson[j].y) {
				k++;
			}
		}
		printf("%d ", k);
	}
}
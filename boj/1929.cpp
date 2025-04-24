#include <stdio.h>
#include <math.h>

int main() {
	const int LIMIT = 1000001;
	bool p[LIMIT] = { 1,1,0 };
	int sLimit = (int)sqrt((double)LIMIT), i, j, tc;
	for (i = 2; i <= sLimit; i++) {
		if (!p[i]) {
			for (j = i * i; j < LIMIT; j += i) p[j] = 1;
		}
	}
	int a, b, cnt = 0;
	scanf("%d %d", &a, &b);
	for (int x = a; x <= b; x++) if (!p[x]) {
        if (cnt++) printf("\n");
        printf("%d", x);
    }
}
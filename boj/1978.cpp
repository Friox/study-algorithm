#include <stdio.h>
#include <math.h>

int main() {
    const int LIMIT = 1001;
	bool p[LIMIT] = { 1,1,0 };
	int sLimit = (int)sqrt((double)LIMIT), i, j, tc;
	for (i = 2; i <= sLimit; i++) {
		if (!p[i]) {
			for (j = i * i; j < LIMIT; j += i) p[j] = 1;
		}
	}
    int N, num[100] = { 0 }, cnt = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
        if (p[num[i]] == 0) cnt++;
    }
    printf("%d", cnt);
}
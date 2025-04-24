#include <stdio.h>
#include <math.h>

int main() {
	const int LIMIT=246913;
	int n, sqrtlimit = (int)sqrt((double)LIMIT);
	bool p[LIMIT] = {1,1,0};
	for (int i=2; i<=sqrtlimit; i++) {
		if (!p[i]) {
			for (int j=i*i; j<LIMIT; j+=i) p[j]=true;
		}
	}
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		int cnt = 0;
		for (int i = n + 1; i <= n * 2; i++) {
			cnt += !p[i];
		}
		printf("%d\n", cnt);
	}
}
#include <stdio.h>
#include <math.h>
int main() {
	const int LIMIT=10001;
	int sqrtlimit = (int)sqrt((double)LIMIT);
	bool p[LIMIT] = {1,1,0};
	for (int i=2; i<=sqrtlimit; i++) {
		if (!p[i]) {
			for (int j=i*i; j<LIMIT; j+=i) p[j]=1;
		}
	}
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		int n, h;
		scanf("%d", &n);
		h = n / 2;
        for (int i = 0; i < h; i++) {
			int a = h - i, b = n - a;
			if (!p[a] && !p[b]) {
				printf("%d %d\n", a, b);
				break;
			}
        }
	}
}
#include <stdio.h>
int main() {
	int p, n, m, f[1500002], cnt;
	scanf("%d", &p);
	while (p--) {
		f[0] = 0; f[1] = 1; cnt = 0;
		scanf("%d %d", &n, &m);
		for (int i = 2; i < 1500002; ++i) {
			f[i] = (f[i - 2] + f[i - 1]) % m;
			++cnt;
			if (!f[i - 1] && f[i] == 1) {
				printf("%d %d\n", n, cnt);
				break;
			}
		}
	}
}
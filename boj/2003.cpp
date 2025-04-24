#include <stdio.h>
int a[10001];
int main() {
	int n, m, cnt = 0, s = 0, e = 0, r;
	scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    r = a[0];
    while (s <= e && e < n) {
        if (r < m) r += a[++e];
        else if (r == m) {
        	++cnt;
            r += a[++e];
        } else if (r > m) {
            r -= a[s++];
            if (s > e) {
                e = s;
                r = a[s];
            }
        }
    }
	printf("%d", cnt);
}
#include <stdio.h>
#include <algorithm>

int main() {
	int n, m, ra[2000000];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; i++) scanf("%d", &ra[i]);
	std::sort(ra, ra + (n + m));
	for (int i = 0; i < n + m; i++) printf("%d ", ra[i]);
}
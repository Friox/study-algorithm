#include <stdio.h>
int a, b, res = 1000000001;
void dfs(long long num, int cnt) {
	if (num > b) return;
	if (num == b) res = (cnt < res ? cnt : res);
	dfs(num * 2, cnt + 1);
	dfs(num * 10 + 1, cnt + 1);
}

int main() {
	scanf("%d %d", &a, &b);
	dfs((long long)a, 1);
	printf("%d", (res == 1000000001 ? -1 : res));
}
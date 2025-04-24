#include <stdio.h>

int n, m, arr[9];
bool visit[9];

void dfs(int now) {
	if (now == m) {
		for (int i = 0; i < m; ++i) printf("%d%c", arr[i], i == m - 1 ? '\n' : ' ');
	} else {
		for (int i = 1; i <= n; ++i) {
			if (!visit[i]) {
				visit[i] = 1;
				arr[now] = i;
				printf("DEBUG : ");
				for (int j = 0; j < m; ++j) printf("%d%c", visit[j], j == m - 1 ? '\n' : ' ');
				dfs(now + 1);
				visit[i] = 0;
			}
		}
	}
}

int main() {
    scanf("%d %d", &n, &m);
	dfs(0);
}
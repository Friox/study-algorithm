#include <stdio.h>
#include <vector>
#include <queue>

std::vector<int> v[32001];
int step[32001], res[32001];

int main() {
	int n, m, a, b;
	std::queue<int> q;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		++step[b];
	}
	for (int i = 1; i <= n; ++i) if (!step[i]) q.push(i);
	for (int i = 1; i <= n; ++i) {
		int tmp = q.front();
		q.pop();
		res[i] = tmp;
		for (int j = 0; j < v[tmp].size(); ++j) {
			if (!(--step[v[tmp][j]])) q.push(v[tmp][j]);
		}
	}
	for (int i = 1; i <= n; ++i) printf("%d ", res[i]);
}
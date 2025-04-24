#include <ios>

int cnt, graph[100001];
bool visited[100001];
bool done[100001];

void cycle( int node) {
	visited[node] = true;
	int next = graph[node];
	if (!visited[next]) cycle(next);
	else if (!done[next]) {
		for (int i = next; i != node; i = graph[i]) cnt++;
		cnt++;
	}
	done[node] = true;
}

int main() {
    int t, n;
    scanf("%d", &t);
	while (t--) {
        scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &graph[i]);
		for (int i = 1; i <= n; i++) if (!visited[i]) cycle(i);
        printf("%d\n", n - cnt);
		cnt = 0;
        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
            done[i] = 0;
        }
	}
}
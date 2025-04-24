#include <stdio.h>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

vector<pair<int, int>> arr[20001];
int dist[20001];

int main() {
	int V, E, k, u, v, w;
	scanf("%d %d %d", &V, &E, &k);
	for (int i = 1; i <= V; ++i) dist[i] = INT_MAX;
	for (int i = 0; i < E; ++i) {
		scanf("%d %d %d", &u, &v, &w);
		arr[u].push_back({v, w});
	}
	priority_queue<pair<int, int>> pq;
	dist[k] = 0;
    pq.push({0, k});
    while (!pq.empty()) {
        int cur = pq.top().second;
        int tmp = -pq.top().first;
        pq.pop();
        if (dist[cur] < tmp) continue;
        for (int i = 0; i < arr[cur].size(); ++i) {
            int next = arr[cur][i].first;
            int nextD = tmp + arr[cur][i].second;
            if (nextD < dist[next]) {
                dist[next] = nextD;
                pq.push({-nextD, next});
            }
        }
    }
	for (int i = 1; i <= V; ++i) {
		if (dist[i] == INT_MAX) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}
#include <ios>
#include <vector>
#include <queue>
#define INF 2147483647
using std::vector, std::priority_queue, std::pair;
typedef pair<int, int> vertex;

int main() {
    int N, M, X, s, e ,t, tmp, res = 0;
    scanf("%d %d %d", &N, &M, &X);
    vector<vector<vector<vertex>>> edges(2, vector<vector<vertex>>(N + 1));
    vector<vector<int>> cost(2, vector<int>(N + 1, INF));
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &s, &e, &t);
        edges[0][e].push_back({s, t}); // FORWARD
        edges[1][s].push_back({e, t}); // BACKWARD
    }
    for (int i = 0; i < 2; ++i) {
        cost[i][X] = 0;
        priority_queue<vertex> q;
        q.push({X, 0});
        while (!q.empty()) {
            int cur = q.top().first;
            int dist = -q.top().second;
            q.pop();
            if (cost[i][cur] < dist) continue;
            for (int j = 0; j < edges[i][cur].size(); ++j) {
                int nextDist = dist + edges[i][cur][j].second;
                int next = edges[i][cur][j].first;
                if (nextDist < cost[i][next]) {
                    cost[i][next] = nextDist;
                    q.push({next, -nextDist});
                }
            }
        }
    }
    for (int i = 1; i <= N; ++i) {
        tmp = cost[0][i] + cost[1][i];
        if (tmp > res) res = tmp;
    }
    printf("%d", res);
}
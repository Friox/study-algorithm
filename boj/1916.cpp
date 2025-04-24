#include <ios>
#include <vector>
#include <queue>
#define INF 2147483647
using std::vector;
typedef std::pair<int, int> info;
int main() {
    int N, M, s, e, c, A, B;
    scanf("%d %d", &N, &M);
    vector<vector<info>> edges(N + 1);
    vector<int> costs(N + 1, INF);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &s, &e, &c);
        edges[e].push_back({s, c});
    }
    scanf("%d %d", &A, &B);
    costs[B] = 0;
    std::priority_queue<info> q;
    q.push({B, 0});
    while (!q.empty()) {
        int cur = q.top().first;
        int cost = -q.top().second;
        q.pop();
        if (costs[cur] < cost) continue;
        for (int i = 0; i < edges[cur].size(); ++i) {
            int next = edges[cur][i].first;
            int nextCost = cost + edges[cur][i].second;
            if (nextCost < costs[next]) {
                costs[next] = nextCost;
                q.push({next, -nextCost});
            }
        }
    }
    printf("%d", costs[A]);
}
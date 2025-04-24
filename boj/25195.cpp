#include <ios>
#include <vector>
#include <queue>
int main() {
    int N, M, u, v, S, s;
    bool visited[100001] = { 0 }, res = 1;
    std::vector<int> node[100001];
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &u, &v);
        node[u].push_back(v);
    }
    scanf("%d", &S);
    for (int i = 0; i < S; ++i) {
        scanf("%d", &s);
        visited[s] = 1;
    }
    if (!visited[1]) {
        std::queue<int> q;
        visited[1] = 1;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (!node[cur].size()) {
                res = 0;
                break;
            }
            for (int& next: node[cur]) {
                if (!visited[next]) {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }
    }
    printf("%s", res ? "Yes" : "yes");
}
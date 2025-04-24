#include <ios>
#include <vector>
#include <queue>

int main() {
    int n, m, a, b;
    int d[32001] = {0, };
    std::vector<int> seq[32001];
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        d[b]++;
        seq[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) if(!d[i]) pq.push(i);
    while (!pq.empty()) {
        int p = pq.top();
        pq.pop();
        printf("%d ", p);
        for (int i = 0; i < seq[p].size(); i++) {
            int next = seq[p][i];
            d[next]--;
            if (!d[next]) pq.push(next);
        }
    }
    printf("\n");
}
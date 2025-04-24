#include <ios>
#include <queue>
#include <vector>
using std::vector, std::queue;
int main() {
    int n, a, b, cur;
    scanf("%d", &n);
    vector<vector<int>> v(n + 1, vector<int>());
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q; q.push(1);
    vector<int> parent(n + 1, 0);
    while(!q.empty()) {
        cur = q.front();
        q.pop();
        for (int num: v[cur]) {
            if (!parent[num] && num != 1) {
                parent[num] = cur;
                q.push(num);
            }
        }
    }
    for (int i = 2; i < n + 1; ++i) printf("%d\n", parent[i]);
}
#include <ios>
#include <unordered_set>

int parent[10001];
int cost[10001];

int find(int n) {
    if (parent[n] == n) return n;
    return find(parent[n]);
}

void make_union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (cost[a] > cost[b]) parent[a] = b;
        else parent[b] = a;
    }
}

int main() {
    // 최소스패닝인가?...
    int N, M, k, v, w, res = 0;
    scanf("%d %d %d", &N, &M, &k);
    for (int i = 1; i <= N; ++i) scanf("%d", &cost[i]);
    for (int i = 1; i <= N; ++i) parent[i] = i;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d", &v, &w);
        make_union(v, w);
    }
    std::unordered_set<int> s;
    for (int i = 1; i <= N; ++i) s.insert(find(i));
    for (int iter: s) res += cost[iter];
    if (res > k) printf("Oh no");
    else printf("%d", res);
}
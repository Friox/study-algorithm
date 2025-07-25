#include <cstdio>
#include <vector>
#include <set>
using std::vector;

struct Edge { 
    int A, B;
    bool operator<(const Edge &e) const {
        if (B == e.B) return A < e.A;
        return B < e.B;
    }
};

class UnionFind {
    vector<Edge> edges;
    vector<int> parent;

    public:
    UnionFind(int N) {
        parent = vector<int>(N + 1);
        for (int i = 1; i <= N; i++) parent[i] = i;
    }

    int findParent(int x) {
        if (parent[x] == x) return x;
        return findParent(parent[x]);
    }

    void unionParent(int A, int B) {
        A = findParent(A);
        B = findParent(B);
        if (A < B) parent[B] = A;
        else parent[A] = B;
    }

    void addEdge(int A, int B) {
        edges.push_back({ A, B });
    }

    void process() {
        for (Edge edge : edges) {
            if (findParent(edge.A) == findParent(edge.B)) continue;
            unionParent(edge.A, edge.B);
        }
    }

    int getParentCount() {
        int size = parent.size(), result = 0;
        for (int i = 1; i <= size; i++) if (parent[i] == i) result++;
        return result;
    }
};

int main() {
    int N, M, s, e;
    scanf("%d %d", &N, &M);
    UnionFind unionFind = UnionFind(N);
    std::set<Edge> edges;
    while (M--) {
        scanf("%d %d", &s, &e);
        bool hasReverse = edges.find({ e, s }) != edges.end();
        if (hasReverse) unionFind.addEdge(s, e);
        else edges.insert({ s, e });
    }
    unionFind.process();
    printf("%d", unionFind.getParentCount());
}
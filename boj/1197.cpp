#include <ios>
#include <vector>
#include <algorithm>

int parent[10001];

struct Vertex {
    int A, B, C;
};

int find(int A) {
    if (A == parent[A]) return A;
    return parent[A] = find(parent[A]);
}

void merge(int A, int B) {
    A = find(A);
    B = find(B);
    parent[B] = A;
}

bool comp(const Vertex& a, const Vertex& b) {
    return a.C < b.C;
}

int main() {
    int V, E, A, B, C;
    long long result = 0;
    std::vector<Vertex> v;
    scanf("%d %d", &V, &E);
    for (int i = 1; i <= V; ++i) parent[i] = i;
    for (int i = 0; i < E; ++i) {
        scanf("%d %d %d", &A, &B, &C);
        v.push_back({A, B, C});
    }
    std::sort(v.begin(), v.end(), comp);
    for (Vertex vt: v) {
        if (find(vt.A) != find(vt.B)) {
            merge(vt.A, vt.B);
            result += vt.C;
        }
    }
    printf("%lld", result);
}
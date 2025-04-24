#include <ios>
#include <vector>
#include <cmath>
#include <algorithm>

int parent[101];
struct Pos { double x, y; };
struct Vertex {
    int a, b;
    double c;
};

double distance(Pos &a, Pos &b) {
    double dx = (a.x - b.x) * (a.x - b.x);
    double dy = (a.y - b.y) * (a.y - b.y);
    return std::sqrt(dx + dy);
}

int find(int n) {
    if (n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[b] = a;
}

bool comp(const Vertex &a, const Vertex &b) {
    return a.c < b.c;
}

int main() {
    int n;
    double x, y, result = 0;
    std::vector<Pos> pv;
    std::vector<Vertex> v;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &x, &y);
        pv.push_back({x, y});
    }
    for (int i = 0; i < pv.size() - 1; i++) {
        for (int j = i + 1; j < pv.size(); j++) {
            double dist = distance(pv[i], pv[j]);
            v.push_back({i, j, dist});
        }
    }
    std::sort(v.begin(), v.end(), comp);
    for (Vertex vt: v) {
        if (find(vt.a) != find(vt.b)) {
            merge(vt.a, vt.b);
            result += vt.c;
        }
    }
    printf("%.2lf", result);
}
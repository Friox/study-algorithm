#include<ios>

int parent[1000001];

int find(int n) {
    if (parent[n] == n) return n;
    return find(parent[n]);
}

void unionParent(int a, int b) {
    a = find(a);
    b = find(b);
    if (a > b) parent[a] = b;
    else parent[b] = a;
}

void findParent(int a, int b) {
    a = find(a);
    b = find(b);
    printf("%s\n", a == b ? "YES" : "NO");
}

int main() {
    int n, m, op, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) parent[i] = i;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &op, &a, &b);
        if (!op) unionParent(a, b);
        else findParent(a, b);
    }
}
#include<ios>

int parent[500001];

int find(int n) {
    if (parent[n] == n) return n;
    return find(parent[n]);
}

bool make_union(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return true;
    else {
        parent[b] = a;
        return false;
    }
}

int main() {
    int N, M, v, w, res = 0;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) parent[i] = i;
    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &v, &w);
        if (make_union(v, w)) {
            res = i;
            break;
        }
    }
    printf("%d", res);
}
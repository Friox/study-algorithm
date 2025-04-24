#include <ios>

int v1[9] = { 0, }, n, m;
bool v2[9] = { 0, };

void loop(int a, int b) {
    if (b == m) {
        for (int i = 0; i < m; ++i) printf("%d ", v1[i]);
        printf("\n");
        return;
    }
    for (int i = a; i <= n; ++i) {
        if (!v2[i]) {
            v2[i] = true;
            v1[b] = i;
            loop(i + 1, b + 1);
            v2[i] = false;
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    loop(1, 0);
}
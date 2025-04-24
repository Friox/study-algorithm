#include <stdio.h>

int main() {
    int n, m, tree[1000000] = {0}, L = 1, M, H = 2000000000, maxHeight = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &tree[i]);
    while (L <= H) {
        long long cnt = 0;
        M = (L + H) / 2;
        for (int i = 0; i < n; i++) {
			int cut = tree[i] - M;
            cnt += (cut < 0 ? 0 : cut);
        }
        if (cnt < m) H = M - 1;
        else {
            L = M + 1;
            maxHeight = maxHeight < M ? M : maxHeight;
        }
    }
    printf("%d\n", maxHeight);
}
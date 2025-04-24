#include <stdio.h>

int main() {
	bool map[101][101] = { 0 };
    int n, m, a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (map[j][i] && map[i][k]) map[j][k] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j && !map[i][j] && !map[j][i]) cnt++;
        }
        printf("%d\n", cnt);
    }
}
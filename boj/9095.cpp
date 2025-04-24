#include <stdio.h>

int main() {
    int T, n;
    int DP[11] = { 0, 1, 2, 4, 0 };
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d", &n);
        for (int j = 4; j <= n; j++) DP[j] = DP[j - 1] + DP[j - 2] + DP[j - 3];
        printf("%d", DP[n]);
        if (i != T - 1) printf("\n");
    }
}
#include <stdio.h>

int main() {
    int matrix[300][300] = { 0 };
    int N, M, K;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    scanf("%d", &K);
    for (int k = 0; k < K; k++) {
        int a, b, c, d, result = 0;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for (int i = a - 1;i <= c - 1; i++) {
            for (int j = b - 1;j <= d - 1; j++) {
                result += matrix[i][j];
            }
        }
        printf("%d", result);
        if (k != K - 1) printf("\n");
    }
}
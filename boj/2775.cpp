#include <stdio.h>

int main() {
    int T, k, n, matrix[15][14] = { {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14}, 0 };
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 14; j++) {
            if (j == 0) matrix[i][j] = 1;
            else matrix[i][j] = matrix[i][j - 1] + matrix[i - 1][j];
        }
    }
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &k, &n);
        printf("%d", matrix[k][n - 1]);
        if (i != T - 1) printf("\n");
    }
}
#include <stdio.h>
#define MAX 1000000000

int main() {
    int matrix[100][100] = { 0 }, node;
    scanf("%d", &node);
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0) matrix[i][j] = MAX;
        }
    }
    // 플로이드 와샬
    // i = 거쳐가는 노드, j = 시작노드, k = 도착노드
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            for (int k = 0; k < node; k++) {
                if (matrix[j][i] + matrix[i][k] < matrix[j][k]) {
                    matrix[j][k] = matrix[j][i] + matrix[i][k];
                }
            }
        }
    }
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            if (matrix[i][j] == MAX) matrix[i][j] = 0;
            else matrix[i][j] = 1;
            if (j != 0) printf(" ");
            printf("%d", matrix[i][j]);
        }
        if (i != node - 1) printf("\n");
    }
}
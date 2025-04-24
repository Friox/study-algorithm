#include <stdio.h>

int main() {
    int a, N, X, cnt = 0;
    scanf("%d %d", &N, &X);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        if (a < X) {
            if (cnt++) printf(" ");
            printf("%d", a);
        }
    }
}
#include <stdio.h>

int main() {
    int tc, a, b;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        scanf("%d %d", &a, &b);
        printf("%d", a + b);
        if (i != tc - 1) printf("\n");
    }
}
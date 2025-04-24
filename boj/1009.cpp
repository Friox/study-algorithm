#include <stdio.h>

int main() {
    int a, b, tc, tmp;
    scanf("%d", &tc);
    while (tc--) {
        tmp = 1;
        scanf("%d %d", &a, &b);
        for (int i = 0; i < b; i++) {
            tmp *= a;
            tmp %= 10;
        }
        printf("%d\n", tmp == 0 ? 10 : tmp);
    }
}

// Comp
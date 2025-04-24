#include <stdio.h>

int main() {
    int a, b[100] = { 0 };
    for (int i = 1; i <= 9; i++) {
        scanf("%d", &a);
        b[a - 1] = i;
    }
    for (int i = 99; i >= 0; i--) {
        if (b[i] != 0) {
            printf("%d\n%d", ++i, b[i]);
            break;
        }
    }
}
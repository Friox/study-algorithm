#include <stdio.h>

int main() {
    int sum = 0, N, i = 5;
    while (i--) {
        scanf("%d", &N);
        sum += (N < 40 ? 40 : N);
    }
    printf("%d", sum / 5);
}
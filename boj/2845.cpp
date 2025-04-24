#include <stdio.h>

int main() {
    int L, P, num;
    scanf("%d %d", &L, &P);
    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        if (i != 0) printf(" ");
        printf("%d", num - L * P);
    }
}
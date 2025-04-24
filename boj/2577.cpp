#include <stdio.h>

int main() {
    char str[10] = { 0 };
    int a, r = 1, cnt[10] = { 0 };
    for (int i = 0; i < 3; i++) {
        scanf("%d", &a);
        r *= a;
    }
    sprintf(str, "%d", r);
    for (int i = 0; i < 10; i++) cnt[str[i] - '0']++;
    for (int i = 0; i < 10; i++) {
        printf("%d", cnt[i]);
        if (i != 9) printf("\n");
    }
}
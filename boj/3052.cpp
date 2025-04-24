#include <stdio.h>

int main() {
    int a, b = 0, cnt[42] = { 0 };
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a);
        cnt[a % 42]++;
    }
    for (int i = 0; i < 42; i++) if(cnt[i]) b++;
    printf("%d", b);
}
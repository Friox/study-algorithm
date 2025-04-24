#include <stdio.h>

int main() {
    int num[2001] = { 0 };
    int N, t, max = -1;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &t);
        if (num[t + 1000] == 0) {
            num[t + 1000] = 1;
            max = (t + 1000 > max ? t + 1000 : max);
        }
    }
    N = 0;
    for (int i = 0; i <= max; i++) {
        if (num[i] == 1) {
            if (N++) printf(" ");
            printf("%d", i - 1000);
        }
    }
}
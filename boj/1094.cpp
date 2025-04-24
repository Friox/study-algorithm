#include <stdio.h>

int main() {
    int num, cnt = 0, mask = 64;
    scanf("%d", &num);
    for (int i = 0; i < 7; i++) {
        if ((num & mask) > 0) cnt++;
        mask = mask >> 1;
    }
    printf("%d", cnt);
}
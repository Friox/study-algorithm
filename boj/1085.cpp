#include <stdio.h>

int main() {
    int x, y, w, h, min = 1000;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    int result[4] = { h - y, y, w - x, x };
    for (int i = 0; i < 4; i++) min = (result[i] < min ? result[i] : min);
    printf("%d", min);
}
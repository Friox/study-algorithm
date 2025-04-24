#include <stdio.h>

int main() {
    int x, y, xB, yB;
    scanf("%d\n%d", &x, &y);
    xB = (x < 0 ? 0 : 1);
    yB = (y < 0 ? 0 : 1);
    if (xB && yB) printf("1");
    else if (!xB && yB) printf("2");
    else if (!xB && !yB) printf("3");
    else printf("4");
}
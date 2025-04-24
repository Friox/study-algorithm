#include <stdio.h>
#include <string.h>

int main() {
    int a, b, bSize;
    char aStr[4] = { 0 }, bStr[4] = { 0 };
    scanf("%d\n%d", &a, &b);
    sprintf(aStr, "%d", a);
    sprintf(bStr, "%d", b);
    bSize = strlen(bStr);
    for (int i = bSize - 1; i >= 0; i--) printf("%d\n", a * (bStr[i] - '0'));
    printf("%d", a * b);
}
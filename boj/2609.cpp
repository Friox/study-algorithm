#include <stdio.h>

int gcd(int a, int b) {
    while (b > 0) {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main() {
    int a, b, mGcd;
    scanf("%d %d", &a, &b);
    mGcd = gcd(a, b);
    printf("%d\n", mGcd);
    printf("%d", a * b / mGcd);
}
#include <cstdio>
#include <cmath>

int main() {
    int W, R;
    scanf("%d %d", &W, &R);
    double result = W * (1 + (R / 30.0));
    printf("%.0f", floor(result));
}
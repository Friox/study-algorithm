#include <cstdio>
#include <cmath>

int main() {
    int T, cnt = 0;
    double X, Y;
    scanf("%d", &T);
    while (T--) {
        scanf("%lf %lf", &X, &Y);
        double A = fmin(X, Y), B = fmax(X, Y);
        double start = A * 1.6, end = A * 1.63;
        if (B >= start && B <= end) cnt++;
    }
    printf("%d", cnt);
}
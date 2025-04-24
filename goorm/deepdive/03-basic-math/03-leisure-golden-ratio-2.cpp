#include <cstdio>
#include <algorithm>

int main() {
    int T, cnt = 0;
    long long X, Y;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld %lld", &X, &Y);
        long long A = std::min(X, Y), B = std::max(X, Y) * 100;
        long long start = A * 160, end = A * 163;
        if (B >= start && B <= end) cnt++;
    }
    printf("%d", cnt);
}
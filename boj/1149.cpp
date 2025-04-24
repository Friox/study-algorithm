#include <ios>
int main() {
    int n, h[1001][3], a, b, c;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        h[i][0] = std::min(h[i - 1][1], h[i - 1][2]) + a;
        h[i][1] = std::min(h[i - 1][0], h[i - 1][2]) + b;
        h[i][2] = std::min(h[i - 1][1], h[i - 1][0]) + c;
    }
    printf("%d", std::min(h[n][2], std::min(h[n][0], h[n][1])));
}
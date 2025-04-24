#include <ios>
int c, n, d, ry, rx;
int main() {
    int N, A, r = -1, t;
    int dir[4][2] = {{ 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 }};
    int arr[999][999] = { 0 };
    scanf("%d %d", &N, &A);
    t = N * N;
    for (int i = N * 2; i > 1; --i, ++d) {
        for (int j = 0; j < i / 2; ++j) {
            r += dir[d % 4][0];
            c += dir[d % 4][1];
            arr[r][c] = t - ++n + 1;
            if (arr[r][c] == A) { ry = r; rx = c; }
        }
    }
    for (int i = 0; i < t; ++i) printf("%d%c", arr[i / N][i % N], i % N == N - 1 ? '\n' : ' ');
    printf("%d %d", ++ry, ++rx);
}
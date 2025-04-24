#include <cstdio>
#include <cmath>

int main() {
    int N, A, P, sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A);
        if (i == 0) { P = A; sum += A; }
        sum += abs(P - A);
        if (i == N - 1) sum += A;
        P = A;
    }
    sum += N * 2;
    printf("%d", sum);
}
#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int A[50] = { 0 };
    int B[50] = { 0 };
    int N, t, sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &A[i]);
    for (int i = 0; i < N; i++) scanf("%d", &B[i]);
    sort(A, A + N);
    sort(B, B + N);
    for (int i = 0; i < N; i++) {
        sum += A[i] * B[(N - 1) - i];
        // printf("%d %d\n", i, (N - 1) - i);
    }
    printf("%d", sum);
}
#include <stdio.h>
int abs(int a) { return (a > 0 ? a : a * -1); }
int main() {
    int N, M, card[100] = { 0 }, result = 0, diff, tmp;
    scanf("%d %d", &N, &M);
    diff = M;
    for (int i = 0; i < N; i++) scanf("%d", &card[i]);
    for (int i = 0; i < N - 2; i++) {
        for (int j = i + 1; j < N - 1; j++) {
            for (int k = j + 1; k < N; k++) {
                tmp = card[i] + card[j] + card[k];
                if (abs(M - tmp) < diff && tmp <= M) {
                    result = tmp;
                    diff = abs(M - tmp);
                }
            }
        }
    }
    printf("%d", result);
}
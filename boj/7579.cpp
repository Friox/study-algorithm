#include <ios>

int main() {
    int N, M, mc = 0, t1[2][100] = { 0 }, t2[2][10001] = { 0 };
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%d", &t1[0][i]);
    for (int i = 0; i < N; i++) {
        scanf("%d", &t1[1][i]);
        mc += t1[1][i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= mc; j++) {
            if (j - t1[1][i] >= 0) t2[1][j] = std::max(t2[1][j], t2[0][j - t1[1][i]] + t1[0][i]);
            t2[1][j] = std::max(t2[0][j], t2[1][j]);
        }
        for (int i = 0; i <= mc; i++) {
            t2[0][i] = t2[1][i];
            t2[1][i] = 0;
        }
    }
    for (int i = 0; i <= mc; i++) {
        if (t2[0][i] >= M) {
            printf("%d", i);
            break;
        }
    }
}
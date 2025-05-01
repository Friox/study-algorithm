#include <cstdio>
#include <vector>
using std::vector;

struct Line { int A, B; };

int main() {
    int N, M, A, B;
    scanf("%d %d", &N, &M);
    vector<int> conn(N + 1), safeLines;
    vector<Line> lines(M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &A, &B);
        conn[A]++; conn[B]++;
        lines[i] = { A, B };
    }
    for (int i = 0; i < M; i++) {
        Line line = lines[i];
        if (conn[line.A] > 1 && conn[line.B] > 1) {
            safeLines.push_back(i + 1);
        }
    }
    if (safeLines.empty()) printf("-1");
    else for (int line : safeLines) printf("%d ", line);
}
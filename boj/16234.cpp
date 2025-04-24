#include <ios>
#include <vector>
#include <queue>
#include <cmath>

struct Pos { int y, x; };

int main() {
    int N, L, R, A[50][50] = { 0 }, idx = 0, cnt = 0;
    int offset[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool visit[50][50] = { 0 };
    scanf("%d %d %d", &N, &L, &R);
    std::vector<std::vector<int>> v((N * N) / 2);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    while (1) {
        std::queue<Pos> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visit[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                bool flag = 0;
                if (visit[i][j] == 0) {
                    visit[i][j] = 1;
                    q.push({i, j});
                    while (!q.empty()) {
                        Pos tmp = q.front();
                        q.pop();
                        for (int k = 0; k < 4; k++) {
                            Pos next = {tmp.y + offset[k][0], tmp.x + offset[k][1]};
                            if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= N) continue;
                            int test = std::abs(A[tmp.y][tmp.x] - A[next.y][next.x]);
                            if (test >= L && test <= R) {
                                v[idx].push_back({})
                            }
                        }
                    }
                }
            }
        }
    }
}
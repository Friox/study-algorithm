#include <stdio.h>
#include <queue>
using namespace std;
struct pos { int n, m; };
void bfs(int map[][50], int visit[][50], pos mPos, int M, int N, int *cnt) {
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    queue<pos> q;
    if (visit[mPos.n][mPos.m] == 0) {
        *cnt += 1;
        q.push({mPos.n, mPos.m});
        visit[mPos.n][mPos.m] = 1;
        while (!q.empty()) {
            int tmpN = q.front().n;
            int tmpM = q.front().m;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nextN = tmpN + direction[i][0];
                int nextM = tmpM + direction[i][1];
                if (nextN >= 0 && nextN < N && nextM >= 0 && nextM < M) {
                    if (map[nextN][nextM] == 1 && visit[nextN][nextM] == 0) {
                        q.push({nextN, nextM});
                        visit[nextN][nextM] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int T = 0;
    scanf("%d", &T);
    while (T--) {
        queue<pos> wait;
        int M, N, K = 0, mM, mN, cnt = 0;
        int map[50][50] = { 0 };
        int visit[50][50] = { 0 };
        scanf("%d %d %d", &M, &N, &K);
        while (K--) {
            scanf("%d %d", &mM, &mN);
            map[mN][mM] = 1;
            wait.push({mN, mM});
        }
        while (!wait.empty()) {
            bfs(map, visit, wait.front(), M, N, &cnt);
            wait.pop();
        }
        printf("%d", cnt);
        if (T != 0) printf("\n");
    }
}
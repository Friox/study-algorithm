#include <ios>
#include <stack>
struct Pos {int y, x;};

int map[1000][1000] = { 0 }, visited[1000][1000] = { 0 }, res = 0;
Pos dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(Pos n) {
    visited[n.y][n.x] = 1;
    Pos next = {n.y + dir[map[n.y][n.x]].y, n.x + dir[map[n.y][n.x]].x};
    if (visited[next.y][next.x] == 1) res++;
    else if (visited[next.y][next.x] == 0) dfs(next);
    visited[n.y][n.x] = 2;
}

int main() {
    char ch;
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf(" %c", &ch);
            if (ch == 'D') map[i][j] = 1;
            else if (ch == 'L') map[i][j] = 2;
            else if (ch == 'R') map[i][j] = 3;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (visited[i][j] == 0) dfs({i, j});
        }
    }
    printf("%d", res);
}
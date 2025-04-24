#include <stdio.h>
#include <queue>
using namespace std;
struct pos { int x, y; };

void bfs(int map[][100], int visit[][100], int N, int M, int startX, int startY) {
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int realX = startX - 1;
    int realY = startY - 1;
    queue<pos> q;
    q.push({realX, realY});
    visit[realY][realX] = 1;
    while (!q.empty()) {
        int tempX = q.front().x;
        int tempY = q.front().y;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = tempX + direction[i][1];
            int nextY = tempY + direction[i][0];
            if ((nextX >= 0 && nextX < M) && (nextY >= 0 && nextY < N)) {
                if (map[nextY][nextX] == 1 && visit[nextY][nextX] == 0) {
                    q.push({nextX, nextY});
                    visit[nextY][nextX] = visit[tempY][tempX] + 1;
                }
            }
        }
    }
}

int main() {
    char map[100][101] = { 0 };
    int N, M, iMap[100][100] = { 0 }, visit[100][100] = { 0 };
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", map[i]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            iMap[i][j] = map[i][j] - '0';
        }
    }
    bfs(iMap, visit, N, M, 1, 1);
    printf("%d", visit[N - 1][M - 1]);
}
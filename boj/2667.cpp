#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;
struct pos { int x, y; };
void bfs(char map[][26], int visit[][25], int N, pos mPos, int* cnt, int cntA[]) {
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    queue<pos> q;
    if (visit[mPos.y][mPos.x]) {
        cntA[visit[mPos.y][mPos.x]]++;
    } else {
        visit[mPos.y][mPos.x] = (*cnt += 1);
        cntA[visit[mPos.y][mPos.x]]++;
        q.push(mPos);
        while (!q.empty()) {
            int tempX = q.front().x;
            int tempY = q.front().y;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nextX = tempX + direction[i][1];
                int nextY = tempY + direction[i][0];
                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N) {
                    if (map[nextY][nextX] == '1' && visit[nextY][nextX] == 0) {
                        q.push({nextX, nextY});
                        visit[nextY][nextX] = *cnt;
                    }
                }
            }
        }
    }
}

int main() {
    char map[25][26] = { 0 };
    int visit[25][25] = { 0 };
    int N, cnt = 0, cntA[615] = { 0 };
    queue<pos> q;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%s", map[i]);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == '1') q.push({j, i});
        }
    }
    while (!q.empty()) {
        bfs(map, visit, N, q.front(), &cnt, cntA);
        q.pop();
    }
    printf("%d\n", cnt);
    sort(cntA, cntA + (cnt + 1));
    for (int i = 1; i <= cnt; i++) {
        printf("%d", cntA[i]);
        if (i != cnt) printf("\n");
    }
}
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct pos { int x, y; };
int bfs(pos n, int map[][100], int visit[][100], int N, int M) {
    int result = 0;
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    if (!(map[n.y][n.x] == 1 || visit[n.y][n.x] == 1)) {
        queue<pos> q1;
        q1.push(n);
        visit[n.y][n.x] = 1;
        result = 1;
        while (!q1.empty()) {
            int tX = q1.front().x;
            int tY = q1.front().y;
            q1.pop();
            for (int i = 0; i < 4; i++) {
                int nextX = tX + direction[i][1];
                int nextY = tY + direction[i][0];
                if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M) {
                    if (map[nextY][nextX] == 0 && visit[nextY][nextX] == 0) {
                        result++;
                        q1.push({nextX, nextY});
                        visit[nextY][nextX] = 1;
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    int map[100][100] = { 0 };
    int visit[100][100] = { 0 };
    int M, N, K, x1, x2, y1, y2, zone = 0, tmp = 0;
    vector<int> v1;
    scanf("%d %d %d", &M, &N, &K);
    while (K--) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        for (int i = y1; i < y2; i++) {
            for (int j = x1; j < x2; j++) {
                map[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int result = bfs({j, i}, map, visit, N, M);
            if (result) {
                zone++;
                v1.push_back(result);
            }
        }
    }
    sort(v1.begin(), v1.end());
    int v1Size = v1.size();
    printf("%d\n", zone);
    for (int i = 0; i < v1Size; i++) {
        if (i) printf(" ");
        printf("%d", v1[i]);
    }
}
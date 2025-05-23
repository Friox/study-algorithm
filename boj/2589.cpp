#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct YX { int y, x; };
YX dirs[4] = {{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};

int main() {
    int N, M, result = -1;
    cin >> N >> M;
    vector<string> board(N);
    for (int i = 0; i < N; i++) cin >> board[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'L') {
                vector<vector<int>> distance(N, vector<int>(M));
                vector<vector<bool>> visited(N, vector<bool>(M));
                queue<YX> q;
                q.push({ i, j });
                visited[i][j] = true;
                while (!q.empty()) {
                    YX now = q.front(); q.pop();
                    for (YX dir : dirs) {
                        YX next = { now.y + dir.y, now.x + dir.x };
                        if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M) continue;
                        if (board[next.y][next.x] == 'W' || visited[next.y][next.x]) continue;
                        distance[next.y][next.x] = distance[now.y][now.x] + 1;
                        visited[next.y][next.x] = true;
                        q.push(next);
                        if (distance[next.y][next.x] > result) result = distance[next.y][next.x];
                    }
                }
            }
        }
    }
    cout << result;
}
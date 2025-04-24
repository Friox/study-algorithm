#include <cstdio>
#include <utility>
int main() {
    // 탐색할 좌표를 기준점과의 Y, X차로 표현하여 저장.
    std::pair<int, int> dir[8] = {
        { -1, -1 }, { -1, +0 }, { -1, +1 },
        { +0, -1 },             { +0, +1 },
        { +1, -1 }, { +1, +0 }, { +1, +1 }
    };
    int N, K, board[1000][1000] = {}, cnt = 0;
    scanf("%d %d", &N, &K);

    // 게임판 입력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) continue;
            int sum = 0;
            for (int k = 0; k < 8; k++) {
                // 8방향 탐색
                int nextY = i + dir[k].first;
                int nextX = j + dir[k].second;
                if ((nextY >= 0 && nextY < N) && (nextX >= 0 && nextX < N)) {
                    if (board[nextY][nextX] == 1) sum++;
                }
            }
            if (sum == K) cnt++;
        }
    }
    printf("%d", cnt);
}
#include <cstdio>
#include <utility>

struct Command { int cnt; char dir; };

int main() {
    // 방향 별 델타, 보드, N 변수 선언
    std::pair<int, int> dir['Z'] = {}, pos[2];
    dir['L'] = { 0, -1 }; dir['R'] = { 0, 1 };
    dir['U'] = { -1, 0 }; dir['D'] = { 1, 0 };
    int N;
    Command board[201][201] = { 0 };
    int score[2] = { 1, 1 };

    // 보드 및 사용자 입력, 시작지점 visited true 설정
    scanf("%d", &N);
    for (int i = 0; i < 2; i++) scanf("%d %d", &pos[i].first, &pos[i].second);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d%c ", &board[i][j].cnt, &board[i][j].dir);
        }
    }
    for (int p = 0; p < 2; p++) {
        bool visited[201][201] = { 0 };
        visited[pos[p].first][pos[p].second] = true;
        bool isOver = false;
        while (true) {
            int nY = pos[p].first;
            int nX = pos[p].second;
            Command now = board[nY][nX];
            for (int i = 0; i < now.cnt; i++) {
                // 다음 좌표를 계산하여 벗어나는 지 판단하고 조정
                nY += dir[now.dir].first;
                nX += dir[now.dir].second;
                if (nY > N) nY = 1;
                else if (nY < 1) nY = N;
                else if (nX > N) nX = 1;
                else if (nX < 1) nX = N;
                if (!visited[nY][nX]) {
                    // 처음 밟는 칸일경우
                    score[p]++;
                    visited[nY][nX] = true;
                    pos[p] = { nY, nX };
                } else {
                    // 밟았던 칸, 게임 끝
                    isOver = true;
                    break;
                }
            }
            if (isOver) break;
        }
    }
    if (score[0] > score[1]) printf("goorm %d", score[0]);
    else printf("player %d", score[1]);
}
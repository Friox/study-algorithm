#include <stdio.h>
#include <queue>

struct pos { int y, x; };

int main() {
	std::queue<pos> mQueue;
	int n, m, k, a, b, cnt, maxCnt = 0, offset[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool map[100][100] = {0}, visit[100][100] = {0};
    scanf("%d %d %d", &n, &m, &k);
	while (k--) {
		scanf("%d %d", &a, &b);
		map[a - 1][b - 1] = 1;
	}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
			cnt = 0;
            if (map[i][j] && !visit[i][j]) {
                cnt++;
                mQueue.push({i, j});
                visit[i][j] = 1;
                while (!mQueue.empty()) {
                    pos nowPos = mQueue.front();
                    mQueue.pop();
                    for (int i = 0; i < 4; i++) {
                        int tY = nowPos.y + offset[i][0];
                        int tX = nowPos.x + offset[i][1];
                        if (tY >= 0 && tY <= n - 1 && tX >= 0 && tX <= m - 1) {
                            if (map[tY][tX] && !visit[tY][tX]) {
								cnt++;
                                mQueue.push({tY, tX});
                                visit[tY][tX] = 1;
                            }
                        }
                    }
                }
            }
			maxCnt = cnt > maxCnt ? cnt : maxCnt;
        }
    }
	printf("%d", maxCnt);
}
#include <stdio.h>
#include <queue>

struct pos { int y, x; };

int main() {
	std::queue<pos> mQueue;
    int n, maxCnt = 0, cnt, map[100][100] = {0}, offset[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    bool sink[100][100] = {0}, visit[100][100] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
        }
    }
    for (int limit = 0; limit <= 100; limit++) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				sink[i][j] = 0;
				visit[i][j] = 0;
			}
		}
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
				sink[i][j] = (map[i][j] > limit);
			}
        }
		for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
				if (sink[i][j] && !visit[i][j]) {
					cnt++;
					mQueue.push({i, j});
					visit[i][j] = 1;
					while (!mQueue.empty()) {
						pos nowPos = mQueue.front();
						mQueue.pop();
						for (int i = 0; i < 4; i++) {
							int tY = nowPos.y + offset[i][0];
							int tX = nowPos.x + offset[i][1];
							if (tY >= 0 && tY <= n - 1 && tX >= 0 && tX <= n - 1) {
								if (sink[tY][tX] && !visit[tY][tX]) {
									mQueue.push({tY, tX});
									visit[tY][tX] = 1;
								}
							}
						}
					}
				}
			}
        }
		if (cnt == 0) break;
		maxCnt = cnt > maxCnt ? cnt : maxCnt;
    }
	printf("%d", maxCnt);
}
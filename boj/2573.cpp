#include <stdio.h>
#include <memory.h>
#include <queue>
#include <utility>
int main() {
	int cycle = 0, cnt = 1, n, m, map[300][300], buffer[300][300], visit[300][300];
	int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &map[i][j]);
		}
    }
    do {
        ++cycle;
		memset(buffer, 0, 90000 * sizeof(int));
		for (int i = 1; i < n - 1; ++i) {
			for (int j = 1; j < m - 1; ++j) {
				if (map[i][j]) {
					int blank = 0;
					for (int k = 0; k < 4; ++k) {
						if (!(map[i + offset[k][0]][j + offset[k][1]])) {
							++blank;
						}
					}
					buffer[i][j] = map[i][j] - blank;
					if (buffer[i][j] < 0) buffer[i][j] = 0;
				}
			}
		}
		memcpy(map, buffer, 90000 * sizeof(int));
		memset(visit, 0, 90000 * sizeof(int));
		std::queue<std::pair<int, int>> q;
		cnt = 0;
		for (int i = 1; i < n - 1; ++i) {
			for (int j = 1; j < m - 1; ++j) {
				if (map[i][j] && !visit[i][j]) {
					cnt++;
					q.push({i, j});
					visit[i][j] = 1;
					while (!q.empty()) {
						std::pair<int, int> tmp = q.front();
						q.pop();
						for (int k = 0; k < 4; ++k) {
							int nY = tmp.first + offset[k][0];
							int nX = tmp.second + offset[k][1];
							if (map[nY][nX] && !visit[nY][nX]) {
								q.push({nY, nX});
								visit[nY][nX] = 1;
							}
						}
					}
				}
			}
		}
		if (!cnt) {
			printf("0");
			return 0;
		}
    } while (cnt == 1);
    printf("%d", cycle);
}
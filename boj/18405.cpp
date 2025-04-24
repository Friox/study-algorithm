#include <stdio.h>
#include <queue>
#include <cstring>
#include <utility>
int main() {
	int n, k, s, x, y;
	int map[200][200] = { 0 }, buffer[200][200];
	int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	std::queue<std::pair<int, int>> q[1001];
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &map[i][j]);
			if (map[i][j]) q[map[i][j]].push({i, j});
		}
	}
	scanf("%d %d %d", &s, &x, &y);
    while (s--) {
        memcpy(buffer, map, 40000 * sizeof(int));
		for (int i = 1; i <= k; ++i) {
			int cnt = q[i].size();
			for (int j = 0; j < cnt; ++j) {
				std::pair<int, int> tmp = q[i].front();
				q[i].pop();
				for (int a = 0; a < 4; ++a) {
					int nY = tmp.first + offset[a][0];
					int nX = tmp.second + offset[a][1];
					if (!(nY < 0 || nY >= n || nX < 0 || nX >= n)) {
						if (!buffer[nY][nX]) {
							buffer[nY][nX] = map[tmp.first][tmp.second];
							q[i].push({nY, nX});
						}
					}
				}
			}
		}
		memcpy(map, buffer, 40000 * sizeof(int));
    }
	printf("%d", map[x - 1][y-1]);
}
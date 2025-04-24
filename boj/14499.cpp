#include <stdio.h>
int main() {
	int val[5][6] = {
		{0},
		{0, 5, 1, 2, 4, 3},
		{0, 2, 3, 5, 4, 1},
		{2, 1, 4, 3, 5, 0},
		{5, 1, 0, 3, 2, 4}
	}, offset[5][2] = {
		{0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}
	}, dice[6] = {0}, buffer[6] = {0}, map[20][20], N, M, x, y, nX, nY, K, cmd;
	scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			scanf("%d", &map[i][j]);
		}
	}
	while (K--) {
		scanf("%d", &cmd);
		nY = y + offset[cmd][0];
		nX = x + offset[cmd][1];
		if (!(nY >= N || nY < 0 || nX >= M || nX < 0)) {
			x = nX; y = nY;
			for (int i = 0; i < 6; ++i) buffer[i] = dice[val[cmd][i]];
			for (int i = 0; i < 6; ++i) dice[i] = buffer[i];
			if (map[y][x]) {
				dice[5] = map[y][x];
				map[y][x] = 0;
			} else {
				map[y][x] = dice[5];
			}
			printf("%d\n", dice[2]);
		}
	}
}
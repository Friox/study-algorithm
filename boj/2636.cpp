#include <stdio.h>
#include <queue>

struct pos { int y, x; };

std::queue<pos> mQueue, requireQueue;
int n, m, offset[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool map[100][100], visit[100][100];

void nextStep() {
	mQueue.push({0, 0});
	visit[0][0] = 1;
	while (!mQueue.empty()) {
		pos mPos = mQueue.front();
		mQueue.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = mPos.y + offset[i][0];
			int nextX = mPos.x + offset[i][1];
			if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < m) {
				if (!visit[nextY][nextX]) {
					if (map[nextY][nextX]) requireQueue.push({nextY, nextX});
					else mQueue.push({nextY, nextX});
					visit[nextY][nextX] = 1;
				}
			}
		}
	}
	while (!requireQueue.empty()) {
		pos mPos = requireQueue.front();
		requireQueue.pop();
		map[mPos.y][mPos.x] = 0;
	}
}

int checkCheese() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j]) cnt++;
		}
	}
	return cnt;
}

int main() {
	int hour = 0, preCnt;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", (int*)&map[i][j]);
		}
	}
	while (checkCheese()) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visit[i][j] = 0;
			}
		}
		hour++;
		preCnt = checkCheese();
		nextStep();
	}
	printf("%d\n%d", hour, preCnt);
}
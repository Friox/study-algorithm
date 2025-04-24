#include <algorithm>
#include <cstddef>
#include <ios>
#include <utility>
#include <queue>

int n, map[20][20] = { 0 }, distance[20][20];
int offset[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool visit[20][20];
std::pair<int, int> mPos;
int mSize = 2, mCnt = 0, sec = 0;

void resetCycle() {
	for (int i = 0; i < n; i++) {
		std::fill_n(visit[i], n, 0);
		std::fill_n(distance[i], n, 0);
	}
}

void printDistance() {
	printf("[DISTANCE]\t[MAP]\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d%s", distance[i][j], (j == n - 1 ? "" : " "));
		}
		printf("\t\t");
		for (int j = 0; j < n; j++) {
			printf("%c%c", (map[i][j] ? map[i][j] == 9 ? '@' : map[i][j] + '0' : '.'), (j == n - 1 ? '\n' : ' '));
		}
	}
	printf("\n");
}

std::pair<int, int> getPos() {
	int min = 2147483647;
	std::pair<int, int> pos = {-1, -1};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] && distance[i][j] > 0 && distance[i][j] < min && map[i][j] < mSize) {
				min = distance[i][j];
				pos = {i, j};
			}
		}
	}
	return pos;
}

void eatFish(std::pair<int, int> pos) {
	++mCnt;
	sec += distance[pos.first][pos.second];
	map[mPos.first][mPos.second] = 0;
	map[pos.first][pos.second] = 9;
	if (mCnt == mSize) {
		mSize++;
		mCnt = 0;
	}
	mPos = pos;
}

void getDistance() {
	resetCycle();
	std::queue<std::pair<int, int>> q;
	q.push(mPos);
	visit[mPos.first][mPos.second] = 1;
	while (!q.empty()) {
		std::pair<int, int> item = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nY = item.first + offset[i][0];
			int nX = item.second + offset[i][1];
			if (nY >= 0 && nY < n && nX >= 0 && nX < n) {
				if (map[nY][nX] <= mSize && !visit[nY][nX]) {
					q.push({nY, nX});
					visit[nY][nX] = 1;
					distance[nY][nX] = distance[item.first][item.second] + 1;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) mPos = {i, j};
		}
	}
	while (1) {
		getDistance();
		// printDistance();
		std::pair<int, int> pos = getPos();
		// printf("Will Pos: %d %d\nNow Size: %d\nNow Cnt: %d\nNow Sec: %d\n\n", pos.first, pos.second, mSize, mCnt, sec);
		if (pos.first == -1) {
			// 없을때
			break;
		} else eatFish(pos);
	}
	printf("%d", sec);
}
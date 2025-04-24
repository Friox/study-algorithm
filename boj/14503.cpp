#include <stdio.h>

int mb[50][50] = { 0 };
int cb[50][50] = { 0 };
int n, m;

class robot {
	public:
	robot(int y, int x, int idx) {
		posY = y;
		posX = x;
		dIdx = idx;
		cb[y][x] = 1;
	}

	void TurnLeft() {
		dIdx += 3;
		dIdx %= 4;
	}

	void Go() {
		posY += dPos[dIdx][0];
		posX += dPos[dIdx][1];
	}

	void Clean() {
		if (cb[posY][posX] == 0) {
			cb[posY][posX] = 1;
			cleanCnt++;
		}
	}

	bool Sequence() {
		if (loopCnt == 4) {
			int nY = posY + (dPos[(dIdx + 2) % 4][0]);
			int nX = posX + (dPos[(dIdx + 2) % 4][1]);
			if (mb[nY][nX] == 1) return 0;
			else {
				posY = nY;
				posX = nX;
				loopCnt = 0;
			}
		}
		TurnLeft();
		int nY = posY + (dPos[dIdx][0]);
		int nX = posX + (dPos[dIdx][1]);
		if (mb[nY][nX] == 0 && cb[nY][nX] == 0) {
			Go();
			Clean();
			loopCnt = 0;
		} else {
			loopCnt++;
		}
		return 1;
	}

	int getCleaned() {
		return cleanCnt;
	}

	private:
	int posY, posX;
	int loopCnt = 0, cleanCnt = 1;
	int dIdx;
	int dPos[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
};

int main() {
	int y, x, d;
	scanf("%d %d %d %d %d", &n, &m, &y, &x, &d);
	robot mRobot = robot(y, x, d);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &mb[i][j]);
		}
	}
	while (mRobot.Sequence());
	printf("%d", mRobot.getCleaned());
}
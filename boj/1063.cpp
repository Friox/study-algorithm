#include <stdio.h>
#include <utility>
typedef std::pair<int, int> unit;

int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
int jumpV[8] = {82, 76, 66, 84, 166, 160, 148, 142};
int jump[167];

class chess {
	public:
	unit king, stone;
	chess(char a[], char b[]) {
		king = {a[1] - '1', a[0] - 'A'};
		stone = {b[1] - '1', b[0] - 'A'};
	}
	void step(int t) {
		// 1. 진행방향이 유효한가?
		if (canGo(king, t)) {
			printf("킹 진행방향 유효\n");
			if (isStone(t)) {
				// 킹 진행방향에 돌이 있으면
				printf("킹 진행방향에 돌있음\n");
				if (canGo(stone, t)) {
					printf("돌 밀고 갈 수 있음\n");
					move(&king, t);
					move(&stone, t);
				}
			} else {
				// 킹 진행방향에 돌이 없으면
				printf("킹 진행방향에 돌 없음\n");
				move(&king, t);
			}
		}
	}

	unit getNextPos(unit target, int t) {
		int nY = target.first + dir[t][0];
		int nX = target.second + dir[t][1];
		return {nY, nX};
	}

	bool canGo(unit target, int t) {
		unit nU = getNextPos(target, t);
		if (nU.first < 0 || nU.first >= 8 || nU.second < 0 || nU.second >= 8) return 0;
		else return 1;
	}

	bool isStone(int t) {
		unit nU = getNextPos(king, t);
		if (nU.first == stone.first && nU.second == stone.second) return 1;
		else return 0;
	}

	void move(unit *target, int t) {
		target->first += dir[t][0];
		target->second += dir[t][1];
	}
};

int main() {
	for (int i = 0; i < 8; ++i) jump[jumpV[i]] = i;
	char k[3], s[3], cmd[3];
	int n;
	scanf("%s %s %d", k, s, &n);
	chess mChess(k, s);
	while (n--) {
		scanf("%s", cmd);
		printf("진행방향 : %d\n", jump[cmd[0] + cmd[1]]);
		mChess.step(jump[cmd[0] + cmd[1]]);
	}
	printf("%c%c\n", mChess.king.second + 'A', mChess.king.first + '1');
	printf("%c%c", mChess.stone.second + 'A', mChess.stone.first + '1');
}
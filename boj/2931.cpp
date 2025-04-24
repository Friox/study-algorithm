#include <stdio.h>

bool yeah[7][4] = {
	{1, 0, 1, 0},	// 1번 파이프
	{0, 1, 0, 1},	// 2번 파이프
	{1, 1, 1, 1},	// 3번 파이프
	{1, 0, 0, 1},	// 4번 파이프
	{0, 0, 1, 1},	// 5번 파이프
	{0, 1, 1, 0},	// 6번 파이프
	{1, 1, 0, 0}	// 7번 파이프
};

int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

class pipe {
	public:
	pipe(char c) {
		int a;
		if (c != '.') {
			if (c == 'M' || c == 'Z') {
				for (int i = 0; i < 4; i++) arr[i] = 0;
			} else {
				if (c == '|') a = 0;
				else if (c == '-') a = 1;
				else if (c == '+') a = 2;
				else if (c == '1') a = 3;
				else if (c == '2') a = 4;
				else if (c == '3') a = 5;
				else a = 6;
				for (int i = 0; i < 4; i++) arr[i] = yeah[a][i];
			}
		}
		ch = c;
	}
	char ch;
	bool arr[4] = { 0 };
};

char pipeCh[7] = {'|', '-', '+', '1', '2', '3', '4'};

int main() {
	int R, C;
	char map[25][26];
	pipe* pMap[25][26];
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) scanf("%s", map[i]);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			pMap[i][j] = new pipe(map[i][j]);
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			// printf("%c", pMap[i][j] -> ch);
			if (pMap[i][j] -> ch == '.') {
				// printf("%d %d\n", i, j);
				bool result[4] = { 0 };
				for (int k = 0; k < 4; k++) {
					int nY = i + offset[k][0];
					int nX = j + offset[k][1];
					if (nY >= 0 && nY < R && nX >= 0 && nX < C) {
						result[k] = pMap[nY][nX] -> arr[k];
					}
				}
				// printf("%d %d { %d %d %d %d }\n", i, j, result[0], result[1], result[2], result[3]);
				for (int k = 0; k < 7; k++) {
					bool flag = 0;
					for (int l = 0; l < 4; l++) {
						if (yeah[k][l] != result[(l + 2) % 4]) flag = 1;
					}
					if (!flag) {
						printf("%d %d %c", i + 1, j + 1, pipeCh[k]);
						return 0;
					}
				}
			}
		}
	}
}
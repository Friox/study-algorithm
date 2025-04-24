#include <stdio.h>

struct pos { int y, x; };

int main() {
	pos chain[26] = { 0 };
	int board[5][5] = { 0 }, n, bingo, cnt;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &n);
			chain[n] = {i, j};
		}
	}
	for (int i = 1; i <= 25; i++) {
		bingo = 0;
		scanf("%d", &n);
		board[chain[n].y][chain[n].x] = 1;
		for (int j = 0; j < 5; j++) {
			cnt = 0;
			for (int k = 0; k < 5; k++) cnt += board[j][k];
			if (cnt == 5) bingo++;
		}
		for (int j = 0; j < 5; j++) {
			cnt = 0;
			for (int k = 0; k < 5; k++) cnt += board[k][j];
			if (cnt == 5) bingo++;
		}
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			cnt += board[j][j];
			if (cnt == 5) bingo++;
		}
		cnt = 0;
		for (int j = 0; j < 5; j++) {
			cnt += board[j][4 - j];
			if (cnt == 5) bingo++;
		}
		if (bingo >= 3) {
			printf("%d", i);
			return 0;
		}
	}
}
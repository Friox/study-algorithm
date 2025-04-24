#include <iostream>
#include <string>
#include <queue>

struct pos { int y, x; };

std::queue<pos> mQueue;
std::string originMap[100];
int n, numMap[100][100], visit[100][100];
int offset[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void arrInit(int gnum) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (originMap[i][j] == 'R') numMap[i][j] = 1;
			else if (originMap[i][j] == 'G') numMap[i][j] = gnum;
			else numMap[i][j] = 3;
			visit[i][j] = 0;
		}
	}
}

void checkZone(int y, int x, int* cnt) {
    if (!visit[y][x]) {
		int target = numMap[y][x];
        (*cnt)++;
        mQueue.push({y, x});
        visit[y][x] = 1;
        while (!mQueue.empty()) {
            pos nowPos = mQueue.front();
            mQueue.pop();
            for (int i = 0; i < 4; i++) {
                int tY = nowPos.y + offset[i][0];
                int tX = nowPos.x + offset[i][1];
                if (tY >= 0 && tY <= n - 1 && tX >= 0 && tX <= n - 1) {
                    if (numMap[tY][tX] == target && !visit[tY][tX]) {
                        mQueue.push({tY, tX});
                        visit[tY][tX] = 1;
                    }
                }
            }
        }
    }
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int a = 0, b = 0;
	std::cin >> n;
	for (int i = 0; i < n; i++) std::cin >> originMap[i];
	arrInit(2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            checkZone(i, j, &a);
        }
    }
	arrInit(1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            checkZone(i, j, &b);
        }
    }
	std::cout << a << ' ' << b;
}
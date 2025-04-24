#include <ios>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

char stage[12][7] = { 0 }, buffer[12][7];
bool visit[12][6] = { 0 };
int offset[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

void dropDown() {
	copy(&stage[0][0], &stage[0][0] + 84, &buffer[0][0]);
	for (int i = 0; i < 6; i++) {
		int cI = 11;
		for (int j = 11; j >= 0; j--) {
			if (buffer[j][i] != '.') stage[cI--][i] = buffer[j][i];
		}
		for (int j = cI; j >= 0; j--) stage[j][i] = '.';
	}
}

void printAll() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) { printf("%c", stage[i][j]); }
        printf("\n");
    }
    printf("\n");
}

int main() {
	int chain = 0;
	bool trigger = true;
	queue<pair<int, int>> q;
	queue<pair<int, int>> dQ;
	for (int i = 0; i < 12; i++) scanf("%s", stage[i]);
	while (trigger) {
		fill_n(&visit[0][0], 72, 0);
		trigger = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (stage[i][j] != '.' && !visit[i][j]) {
					int cnt = 1;
					char c = stage[i][j];
					q.push(make_pair(i, j));
					dQ.push(make_pair(i, j));
					visit[i][j] = 1;
					while (!q.empty()) {
						pair<int, int> item = q.front();
						q.pop();
						for (int i = 0; i < 4; i++) {
							int nY = item.first + offset[i][0];
							int nX = item.second + offset[i][1];
							if (nY >= 0 && nY < 12 && nX >= 0 && nX < 6 && stage[nY][nX] == c && !visit[nY][nX]) {
								visit[nY][nX] = 1;
								dQ.push(make_pair(nY, nX));
								q.push(make_pair(nY, nX));
								cnt++;
							}
						}
					}
					if (cnt >= 4) {
						// 4개이상일때
						while (!dQ.empty()) {
							pair<int, int> item = dQ.front();
                            stage[item.first][item.second] = '.';
                            dQ.pop();
                        }
                        // printAll();
                        trigger = true;
					} else {
						dQ = queue<pair<int, int>>();
					}
				}
			}
		}
		if (trigger) {
			dropDown();
			// printAll();
			chain++;
		}
	}
	printf("%d", chain);
}
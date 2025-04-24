#include <stdio.h>
#include <queue>

struct pos { int y, x; };

int main() {
	std::queue<pos> mQueue;
	int w, h, cnt, n, offset[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	bool map[50][50] = { 0 }, visit[50][50] = { 0 };
	while (1) {
		cnt = 0;
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) return 0;

		// 테스트케이스 반복이라 방문을 표시한 배열을 초기화해줘야함.
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				visit[i][j] = 0;
			}
		}

		// for문으로 좌표하나씩 이동하면서 1, 0을 입력받아서 해당 좌표에 표시
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &n);
				map[i][j] = (n ? 1 : 0);
			}
		}

		// BFS할거임.
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				// 맵이 1(검은색)이고, 방문하지 않은곳이라면, 해당좌표를 시작으로 BFS실행
				if (map[i][j] && !visit[i][j]) {
					cnt++; // BFS를 시작한다는것은 해당좌표를 기준으로 연결된곳은 전부 하나의 섬이라는것이니 섬갯수 하나 올려주고
					mQueue.push({i, j});
					visit[i][j] = 1;
					while (!mQueue.empty()) {
						pos nowPos = mQueue.front();
						mQueue.pop();
						for (int i = 0; i < 8; i++) {
							// 오프셋으로 대각선과 상하좌우를 체크.
							// 그 좌표가 1(검은색)이고, 방문하지않았으면 큐에 집어넣고 방문표시하기.
							int tY = nowPos.y + offset[i][0];
							int tX = nowPos.x + offset[i][1];
							if (tY >= 0 && tY <= h - 1 && tX >= 0 && tX <= w - 1) {
								if (map[tY][tX] && !visit[tY][tX]) {
									mQueue.push({tY, tX});
									visit[tY][tX] = 1;
								}
							}
						}
					}
				}
			}
		}

		// 그렇게 모든좌표를 검사하면 cnt는 섬이 몇개인지 담고있음.
		printf("%d\n", cnt);
	}
}
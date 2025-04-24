#include <stdio.h>
#include <algorithm>
#include <vector>
int right[4][2] = {{1, 3}, {3, 2}, {2, 4}, {4, 1}};
int main() {
	int k, d, l, privD, privL, firstD, firstL, minus;
	std::vector<int> h, v;
	bool first = true, lock;
	scanf("%d", &k);
	for (int i = 0; i < 6; ++i) {
		scanf("%d %d", &d, &l);
		printf("%d %d, %d %d\n", privD, privL, d, l);
		if (d < 3) h.push_back(l);
		else v.push_back(l);
		if (first) {
			// 처음일때 그냥 진행
			firstD = d;
			firstL = l;
			first = false;
		} else {
			for (int j = 0; j < 4; ++j) {
				if (right[j][0] == privD && right[j][1] == d) {
					// 시계방향일때, 마이너스에 대입
					minus = privL * l;
					break;
				}
			}
		}
		if (i == 5) {
			for (int j = 0; j < 4; ++j) {
				if (right[j][0] == d && right[j][1] == firstD) {
					// 시계방향일때, 마이너스에 대입
					minus = firstL * l;
					break;
				}
			}
		}
		privD = d;
		privL = l;
	}
	std::sort(h.begin(), h.end());
	std::sort(v.begin(), v.end());
	printf("minus: %d, maxH: %d, maxV: %d\n", minus, h[2], v[2]);
	printf("%d", (h[2] * v[2] - minus) * k);		
}
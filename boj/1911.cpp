#include <stdio.h>
#include <utility>
#include <algorithm>
int main() {
	int N, L, cnt = 0, now = 0;
	scanf("%d %d", &N, &L);
	std::pair<int, int> p[N];
	for (int i = 0; i < N; ++i) scanf("%d %d", &p[i].first, &p[i].second);
	std::sort(p, p + N);
	for (int i = 0; i < N; ++i) {
		if (now >= p[i].second) continue;
		if (now < p[i].first) now = p[i].first;
		while (now < p[i].second) { ++cnt; now += L; }
	}
	printf("%d", cnt);
}
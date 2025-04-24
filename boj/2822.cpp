#include <stdio.h>
#include <algorithm>

struct scoreSet { int score, idx; };

bool scoreSort(scoreSet a, scoreSet b) { return a.score < b.score; }
bool idxSort(scoreSet a, scoreSet b) { return a.idx < b.idx; }

int main() {
	int sum = 0;
	scoreSet score[8] = { 0 };
	for (int i = 1; i <= 8; i++) {
		scanf("%d", &score[i - 1].score);
		score[i - 1].idx = i;
	}
	std::sort(score, score + 8, scoreSort);
	for (int i = 3; i < 8; i++) sum += score[i].score;
	std::sort(score + 3, score + 8, idxSort);
	printf("%d\n", sum);
	for (int i = 3; i < 8; i++) printf("%d ", score[i].idx);
}
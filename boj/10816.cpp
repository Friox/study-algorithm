#include <stdio.h>
#include <algorithm>
using namespace std;

int N, M;
int card[500000];

int upperBound(int n) {
	int f = 0, l = N - 1, m;
	for (;;) {
		m = (f + l) / 2;
		if (f > l) {
			if (card[l] == n) return l;
			else return -1;
        }
		if (card[m] <= n) f = m + 1;
		else l = m - 1;
	}
}

int lowerBound(int n) {
	int f = 0, l = N - 1, m;
	for (;;) {
		m = (f + l) / 2;
		if (f > l) {
			if (card[f] == n) return f;
			else return -1;
		}
		if (card[m] >= n) l = m - 1;
		else f = m + 1;
	}
}

int main() {
    int n, val, cnt = 0;
    scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &card[i]);
	sort(card, card + N);
    scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &n);
		val = upperBound(n);
		if (val == -1) {
            if (cnt++) printf(" ");
            printf("0");
        } else {
            if (cnt++) printf(" ");
            printf("%d", val - lowerBound(n) + 1);
        }
	}
}
#include <stdio.h>
#include <queue>
using namespace std;
typedef struct {
    int i, j, mDay;
} pos;

int availZero(int arr[][1000], int M, int N) { 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) return 1;
        }
    }
    return 0;
}

int solve() {
    queue<pos> tomatoQ;
    int tomato[1000][1000];
    int direction[4][2] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
    int M, N, maxDay = 0;;
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &tomato[i][j]);
            if (tomato[i][j] == 1) tomatoQ.push({i, j, 0});
        }
    }
    while (!tomatoQ.empty()) {
        int i = tomatoQ.front().i;
        int j = tomatoQ.front().j;
        int day = tomatoQ.front().mDay;
        tomatoQ.pop();
        maxDay = day;
        for (int d = 0; d < 4; d++) {
            int nextI = i + direction[d][0];
            int nextJ = j + direction[d][1];
            if (nextI < 0 || nextJ < 0 || nextI >= N || nextJ >= M) continue;
            if (tomato[nextI][nextJ] == 0) {
                tomatoQ.push({nextI, nextJ, day + 1});
                tomato[nextI][nextJ] = 1;
            }
        }
    }
    if (availZero(tomato, M, N)) printf("-1");
    else printf("%d", maxDay);
    return 0;
}

int main() {
    solve();
}
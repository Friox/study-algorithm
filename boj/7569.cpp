#include <stdio.h>
#include <queue>
using namespace std;
typedef struct {
    int i, j, k, mDay;
} pos;

int availZero(int arr[][100][100], int M, int N, int H) { 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < M; k++) {
                if (arr[i][j][k] == 0) return 1;
            }
        }
    }
    return 0;
}

int solve() {
    queue<pos> tomatoQ;
    int tomato[100][100][100];
    int direction[6][3] = { {0,0,-1},{0,0,1},{0,-1,0},{0,1,0},{-1,0,0},{1,0,0} };
    int M, N, H, maxDay = 0;;
    scanf("%d %d %d", &M, &N, &H);
    for (int i = H - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            for (int k = 0; k < M; k++) {
                scanf("%d", &tomato[j][i][k]);
                if (tomato[j][i][k] == 1) tomatoQ.push({j, i, k, 0});
            }
        }
    }
    while (!tomatoQ.empty()) {
        int i = tomatoQ.front().i;
        int j = tomatoQ.front().j;
        int k = tomatoQ.front().k;
        int day = tomatoQ.front().mDay;
        tomatoQ.pop();
        maxDay = day;
        for (int d = 0; d < 6; d++) {
            int nextI = i + direction[d][0];
            int nextJ = j + direction[d][1];
            int nextK = k + direction[d][2];
            if (nextI < 0 || nextJ < 0 || nextK < 0 || nextI >= N || nextJ >= H || nextK >= M) continue;
            if (tomato[nextI][nextJ][nextK] == 0) {
                tomatoQ.push({nextI, nextJ, nextK, day + 1});
                tomato[nextI][nextJ][nextK] = 1;
            }
        }
    }
    if (availZero(tomato, M, N, H)) printf("-1");
    else printf("%d", maxDay);
    return 0;
}

int main() {
    solve();
}
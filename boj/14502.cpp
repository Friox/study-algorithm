#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
struct pos { int n, m; };

void diffusionVirus(int sandbox[][8], int N, int M, vector<pos> virusV) {
    int direction[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    queue<pos> q;
    int visit[8][8] = { 0 };
    int virusCnt = virusV.size();
    for (int i = 0; i < virusCnt; i++) {
        visit[virusV[i].n][virusV[i].m] = 1;
        q.push({virusV[i].n, virusV[i].m});
        while (!q.empty()) {
            int originN = q.front().n;
            int originM = q.front().m;
            q.pop();
            for (int j = 0; j < 4; j++) {
                int nextN = originN + direction[j][0];
                int nextM = originM + direction[j][1];
                if (nextN >= 0 && nextN < N && nextM >= 0 && nextM < M) {
                    if (sandbox[nextN][nextM] == 0 && visit[nextN][nextM] == 0) {
                        q.push({nextN, nextM});
                        visit[nextN][nextM] = 1;
                        sandbox[nextN][nextM] = 2;
                    }
                }
            }
        }
    }
}

int checkSafe(int sandbox[][8], int N, int M) {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (sandbox[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void copyMap(int map[][8], int sandbox[][8], int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sandbox[i][j] = map[i][j];
        }
    }
}

int main() {
    vector<pos> virusV;
    vector<pos> zeroV;
    int map[8][8] = { 0 };
    int sandbox[8][8] = { 0 };
    int N, M, zeroCnt, max = -1;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 0) zeroV.push_back({i, j});
            else if (map[i][j] == 2) virusV.push_back({i, j});
        }
    }
    zeroCnt = zeroV.size();
    for (int i = 0; i < zeroCnt - 2; i++) {
        for (int j = i + 1; j < zeroCnt - 1; j++) {
            for (int k = j + 1; k < zeroCnt; k++) {
                map[zeroV[i].n][zeroV[i].m] = 1;
                map[zeroV[j].n][zeroV[j].m] = 1;
                map[zeroV[k].n][zeroV[k].m] = 1;
                copyMap(map, sandbox, N, M);
                diffusionVirus(sandbox, N, M, virusV);
                int temp = checkSafe(sandbox, N, M);
                max = (temp > max ? temp : max);
                map[zeroV[i].n][zeroV[i].m] = 0;
                map[zeroV[j].n][zeroV[j].m] = 0;
                map[zeroV[k].n][zeroV[k].m] = 0;
            }
        }
    }
    printf("%d", max);
}
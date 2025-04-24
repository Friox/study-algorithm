#include <stdio.h>
#include <queue>
using namespace std;
int bfs(int num, int map[][1001], int visit[1001], int N) {
    int result = -1;
    if (visit[num] == 1) result = 0;
    else {
        queue<int> bfsQ;
        bfsQ.push(num);
        visit[num] = 1;
        while (!bfsQ.empty()) {
            int tNum = bfsQ.front();
            bfsQ.pop();
            for (int i = 1; i <= N; i++) {
                if (map[tNum][i] == 1 && visit[i] == 0) {
                    bfsQ.push(i);
                    visit[i] = 1;
                } 
            }
        }
        result = 1;
    }
    return result;
}

int main() {
    int map[1001][1001] = { 0 };
    int visit[1001] = { 0 };
    int N, M, s, t, cnt = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &s, &t);
        map[s][t] = 1;
        map[t][s] = 1;
    }
    for (int i = 1; i <= N; i++) cnt += bfs(i, map, visit, N);
    printf("%d", cnt);
}
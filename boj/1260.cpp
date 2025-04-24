#include <stdio.h>
#include <queue>
using namespace std;

char bfsVisit[1001] = { 0 };
char dfsVisit[1001] = { 0 };
int node[1001][1001] = { 0 }, dfsLock = 0, bfsLock = 0;

void dfs(int n) {
    if (dfsVisit[n] == 'v') return;
    dfsVisit[n] = 'v';
    if (dfsLock) printf(" ");
    dfsLock = 1;
    printf("%d", n);
    for (int i = 1; i <= 1000; i++) if (node[n][i] == 1) dfs(i);
}

void bfs(int n) {
    queue<int> q;
    q.push(n);
    bfsVisit[n] = 'v';
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (bfsLock) printf(" ");
        bfsLock = 1;
        printf("%d", x);
        for (int i = 1; i <= 1000; i++) {
            if (node[x][i] == 1) {
                if (bfsVisit[i] != 'v') {
                    q.push(i);
                    bfsVisit[i] = 'v';
                }
            }
        }
    }
}

int main() {
    int N, M, V, iN, iM;
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &iN, &iM);
        node[iN][iM] = 1;
        node[iM][iN] = 1;
    }
    dfs(V);
    printf("\n");
    bfs(V);
}
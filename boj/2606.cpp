#include <stdio.h>
#include <stack>
using namespace std;
void dfs(int matrix[][100], int visit[], int size, int v) {
    int flag;
    stack<int> s1;
    s1.push(v);
    visit[v - 1] = 1;
    while (!s1.empty()) {
        int vv = s1.top();
        flag = 0;
        for (int i = 1; i <= size; i++) {
            if (matrix[vv - 1][i - 1] == 1 && !visit[i - 1]) {
                // 탐색할 노드가 현재노드와 연결되어있고 탐색하지 않았으면
                s1.push(i);
                visit[i - 1] = 1;
                flag = 1;
                break;
            }
        }
        if (!flag) s1.pop();
    }
}

int main() {
    int matrix[100][100] = { 0 }, visit[100] = { 0 }, size, pair;
    scanf("%d", &size);
    scanf("%d", &pair);
    for (int i = 0; i < pair; i++) {
        int node, target;
        scanf("%d %d", &node, &target);
        matrix[node - 1][target - 1] = 1;
        matrix[target - 1][node - 1] = 1;
    }
    dfs(matrix, visit, size, 1);
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (visit[i] == 1) result++;
    }
    printf("%d", result - 1);
}
#include <cstdio>
#include <vector>
#include <stack>
using std::vector, std::stack;

int main() {
    // 과거에 풀었던 그래프 탐색문제는 주어진 데이터에서 탐색을 수행했습니다.
    // 이 문제같은 경우 주어진 데이터를 가공한 후 탐색을 진행합니다.
    // 양방향 연결이 되어있어야만 연결이 된것으로 판단하기때문에
    // 아예길이없거나 어느 한쪽이라도 연결이 되어있지 않으면 아예 연결을 끊습니다.
    // 최종적으로는 쌍방향 연결이 되어있던 곳들만 서로 연결 되어있을것이고,
    // 그 상태에서 DFS, BFS 탐색을 진행합니다. 탐색횟수가 곧 답입니다.
    int N, M, s, e, res = 0;
    scanf("%d %d", &N, &M);
    vector<vector<bool>> board(N + 1, vector<bool>(N + 1, false));
    vector<bool> v(N + 1, false);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &s, &e);
        board[s][e] = true; // 시작노드로부터 끝노드 간 연결되었다고 표시
    }
    // 예시 1번기준 인접행렬은 다음과 같음
    // 자신 노드로부터 자신노드로 가는것도 가능하다고 체크
    // 행 -> 열: (~에서) -> (~로)
    //      1   2   3   4
    // 1    1   1   0   1
    // 2    0   1   1   1
    // 3    0   0   1   1
    // 4    1   0   0   1
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == j) board[i][j] = true; // 자기자신
            if (!board[i][j] || board[i][j] != board[j][i]) {
                // 쌍방향 연결이 되어있지 않거나 어느 한쪽이라도 길이없다면
                // 연결 끊어버리기
                board[i][j] = false;
                board[j][i] = false;
            }
        }
    }

    // 이상태에서 DFS를 수행합니다.
    for (int i = 1; i <= N; i++) {
        if (v[i]) continue; // 현재 탐색중인 노드에 방문하지 않았다면,
        stack<int> s;
        v[i] = true;
        res++; // 탐색 카운트 +1
        s.push(i);
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            for (int j = 1; j <= N; j++) {
                // 현재 노드와 연결된 노드를 탐색합니다. (행 탐색)
                if (board[cur][j] && !v[j]) {
                    // 갈수있는 도착노드가 만약 방문하지 않았던 노드라면
                    // 탐색예정노드 스택에 넣습니다.
                    s.push(j);
                    v[j] = true; // 넣고 그 노드는 방문했다고 표시.
                    // 이후 while문에 의해 반복
                }
            }
        }
    }
    printf("%d", res);
}
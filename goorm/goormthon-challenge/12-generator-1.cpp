#include <cstdio>
#include <stack>
struct Pair { int y, x; };
int main() {
  // 전형적인 DFS, BFS 문제
  // 인접한 1로 이루어진 그룹 개수를 찾으면 됩니다.
  // 탐색 횟수가 곧 답입니다. (1)
  // 이를 위해 다음 좌표를 스택이나 큐에 저장할때 조건을 걸어주면 됩니다. (2)
  int board[1000][1000] = {0}, N, cnt = 0;
  std::stack<Pair> s;
  Pair dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  bool v[1000][1000] = {0};
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 1 && !v[i][j]) {
        // 해당 지점이 집이고 방문하지 않았다면
        cnt++; // (1)
        s.push({i, j});
        v[i][j] = true;
        while (!s.empty()) {
          Pair cur = s.top();
          s.pop();
          for (Pair c : dir) {
            Pair n = {cur.y + c.y, cur.x + c.x};
            if (n.y < 0 || n.y >= N || n.x < 0 || n.x >= N) continue;
            if (board[n.y][n.x] == 0 || v[n.y][n.x]) continue; // (2)
            v[n.y][n.x] = true;
            s.push(n);
          }
        }
      }
    }
  }
  printf("%d", cnt);
}
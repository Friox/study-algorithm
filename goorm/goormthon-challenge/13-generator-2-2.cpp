#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
struct Coord { int y, x; };
struct Pair { int a, b; };

bool compare(const Pair &x, const Pair &y) {
  // (1)
  // 단지카운트 1순위, 유형 2순위로 하여 정렬
  // 정렬 시 앞에있는게 a, 뒤에있는게 b라고 했을때
  // 이 비교함수의 결과가 true일경우 서로 자리를 바꿈.
  // 먼저 단지카운트를 비교하여 같다면 단지유형을 비교하여 반환
  // 같지않다면 단지카운트를 비교하여 반환
  // 내림차순이기때문에 a가 더 크면 서로 자리를 바꿈.
  if (x.b == y.b) return x.a > y.a;
  return x.b > y.b;
}

int main() {
  int board[1000][1000] = {0}, N, K, max = 0;
  std::stack<Coord> s;
  Coord dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  bool v[1000][1000] = {0};
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
      if (board[i][j] > max) max = board[i][j];
    }
  }
  std::vector<Pair> arr(max + 1);
  for (int i = 1; i <= max; i++) arr[i].a = i;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!v[i][j]) {
        // 방문한 적이 없다면
        int t = board[i][j], cnt = 1; // t == type
        s.push({i, j});
        v[i][j] = true;
        while (!s.empty()) {
          Coord cur = s.top();
          s.pop();
          for (Coord c : dir) {
            Coord n = {cur.y + c.y, cur.x + c.x};
            if (n.y < 0 || n.y >= N || n.x < 0 || n.x >= N) continue;
            if (board[n.y][n.x] != t || v[n.y][n.x]) continue;
            cnt++;
            v[n.y][n.x] = true;
            s.push(n);
          }
        }
        if (cnt >= K) arr[t].b++;
      }
    }
  }
  std::sort(arr.begin(), arr.end(), compare); // comapre (1)
  printf("%d", arr[0].a);
}
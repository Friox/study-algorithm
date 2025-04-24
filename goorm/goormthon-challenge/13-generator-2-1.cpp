#include <cstdio>
#include <stack>
#include <map>
#include <vector>
#include <algorithm>
#define pair std::pair<int, int>
struct Coord { int y, x; };

bool compare(const pair &a, const pair &b) {
  // 정렬 시 앞에있는게 a, 뒤에있는게 b라고 했을때
  // 이 비교함수의 결과가 true일경우 서로 자리를 바꿈.
  // 먼저 단지카운트를 비교하여 같다면 단지유형을 비교하여 반환
  // 같지않다면 단지카운트를 비교하여 반환
  // 내림차순이기때문에 a가 더 크면 서로 자리를 바꿈.
  if (a.second == b.second) return a.first > b.first;
  return a.second > b.second;
}

int main() {
  int board[1000][1000] = {0}, N, K;
  std::stack<Coord> s;
  std::map<int, int> m; // <유형, 단지카운트> 형태로 구성
  Coord dir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  bool v[1000][1000] = {0};
  scanf("%d %d", &N, &K);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &board[i][j]);
    }
  }
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
        if (cnt >= K) {
          // 만약 건물 수가 단지 기준수보다 같거나 크다면 후보에 삽입
          m.insert({t, 0}); // 이미 있는 유형이면 무시됨.
          m[t]++;
        }
      }
    }
  }

  // map
  // value기준으로 정렬을 위해 맵을 배열(벡터)로 바꾸고
  // 단지카운트 1순위, 유형 2순위로 하여 정렬 (상단 compare 함수)
  std::vector<pair> vec(m.begin(), m.end());
  std::sort(vec.begin(), vec.end(), compare);
  printf("%d", vec[0].first);
}
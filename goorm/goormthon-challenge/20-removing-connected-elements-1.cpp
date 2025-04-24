#include <cstdio>
#include <vector>
#include <stack>
using std::vector;
template <typename T>
using Matrix = vector<vector<T>>; // 2차원 배열 타입 별칭
struct YX {
    // y, x 좌표를 편하게 다루기 위한 사용자 지정 구조체
    int y, x;
    // 구조체 간 연산을 편하게 하기 위해 연산자 오버라이딩
    YX operator+(const YX &t) { return { y + t.y, x + t.x }; }
};
// 상하좌우 벡터
YX UDLR[4] = {{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};
int N, K; // 함수 간 공유위해 전역변수 지정

void process(Matrix<char> &board, Matrix<bool> &visited, int i, int j) {
    // 코드 깊이 증가로 별도의 함수로 분리
    // 만약 현재 칸의 문자가 '.'이 아닌경우, 탐색을 시작합니다.
    if (board[i][j] != '.') {
        char target = board[i][j]; // 비교 대상문자 지정(1)
        std::stack<YX> s; // DFS 사용을 위한 스택
        // 삭제 후보를 담을 배열, 현재 위치도 삭제될 수 있으니 후보에 넣습니다.
        vector<YX> toBeDeleted = {{ i, j }};
        visited[i][j] = true; // DFS 탐색을 위해 현재 칸 방문표시.
        s.push({ i, j });
        while (!s.empty()) {
            YX cur = s.top(); s.pop();
            for (YX dir : UDLR) {
                // 현재 칸으로부터 상하좌우 탐색합니다.
                // 다음 칸이 좌표를 벗어나거나 이미 방문했으면 루프를 건너뜁니다.
                YX next = cur + dir;
                if (next.y < 1 || next.y > N || next.x < 1 || next.x > N) continue;
                if (visited[next.y][next.x]) continue;
                if (board[next.y][next.x] == target) {
                    // 만약 다음 칸이 대상 문자(1)와 같으면 삭제 후보에 넣고
                    // 방문표시 한 후 탐색 예정 스택에 넣습니다.
                    toBeDeleted.push_back(next);
                    s.push(next);
                    visited[next.y][next.x] = true;
                }
            }
        }
        if (toBeDeleted.size() >= K) {
            // 만약 삭제 후보 개수가 K개 이상인 경우
            // 좌표를 하나씩 꺼내서 삭제('.') 합니다.
            for (YX pos : toBeDeleted) {
                board[pos.y][pos.x] = '.';
            }
        }
    }
}

int main() {
    int Q, y, x;
    char ch;
    scanf("%d %d %d", &N, &K, &Q);
    // 보드 2차원 배열 (N x N)
    Matrix<char> board(N + 1, vector<char>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf(" %c", &board[i][j]); // 보드 입력
        }
    }
    while (Q--) {
        // Y, X, 문자 입력
        scanf("%d %d %c", &y, &x, &ch);
        board[y][x] = ch;
        // DFS 탐색을 위한 방문여부 배열 (N x N)
        Matrix<bool> visited(N + 1, vector<bool>(N + 1));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // 현재 칸 문자에 대해 함수 실행
                process(board, visited, i, j);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 보드 출력
            printf("%c", board[i][j]);
        }
        if (i != N) printf("\n");
    }
}
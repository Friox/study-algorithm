#include <cstdio>
#include <vector>
#include <stack>
using std::vector;
template <typename T>
using Matrix = vector<vector<T>>;
struct YX {
    int y, x;
    YX operator+(const YX &t) { return { y + t.y, x + t.x }; }
};
YX UDLR[4] = {{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};
int N, K;

void process(Matrix<char> &board, Matrix<bool> &visited, int i, int j) {
    if (board[i][j] != '.') {
        char target = board[i][j];
        std::stack<YX> s;
        vector<YX> toBeDeleted = {{ i, j }};
        visited[i][j] = true;
        s.push({ i, j });
        while (!s.empty()) {
            YX cur = s.top(); s.pop();
            for (YX dir : UDLR) {
                YX next = cur + dir;
                if (next.y < 1 || next.y > N || next.x < 1 || next.x > N) continue;
                if (visited[next.y][next.x]) continue;
                if (board[next.y][next.x] == target) {
                    toBeDeleted.push_back(next);
                    s.push(next);
                    visited[next.y][next.x] = true;
                }
            }
        }
        if (toBeDeleted.size() >= K) {
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
    Matrix<char> board(N + 1, vector<char>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) scanf(" %c", &board[i][j]);
    }
    while (Q--) {
        scanf("%d %d %c", &y, &x, &ch);
        board[y][x] = ch;
        Matrix<bool> visited(N + 1, vector<bool>(N + 1));
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                process(board, visited, i, j);
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) printf("%c", board[i][j]);
        if (i != N) printf("\n");
    }
}
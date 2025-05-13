#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct YX {
    int y, x;
    YX operator+(const YX &v) const {
        return { y + v.y, x + v.x };
    }
} dirs[4] = {{ -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }};
int R, C, result = 0;

void dfs(vector<string> &board, vector<bool> &visited, YX pos, int count) {
    if (count > result) result = count;
    for (YX dir : dirs) {
        YX next = pos + dir;
        if (next.y < 0 || next.y >= R || next.x < 0 || next.x >= C) continue;
        if (visited[board[next.y][next.x] - 'A']) continue;
        visited[board[next.y][next.x] - 'A'] = true;
        dfs(board, visited, next, count + 1);
        visited[board[next.y][next.x] - 'A'] = false;
    }
}

int main() {
    string str;
    cin >> R >> C;
    vector<string> board(R);
    vector<bool> visited(26);
    for (int i = 0; i < R; i++) cin >> board[i];
    visited[board[0][0] - 'A'] = true;
    dfs(board, visited, { 0, 0 }, 1);
    cout << result;
}
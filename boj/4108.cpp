#include <cstdio>

int main() {
    int R, C;
    while (scanf("%d %d", &R, &C)) {
        if (R == 0 && C == 0) break;
        char board[100][101] = { 0 };
        for (int i = 0; i < R; i++) scanf("%s", board[i]);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (board[i][j] != '*') continue;
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        int y = i + dy, x = j + dx;
                        if (y < 0 || y >= R || x < 0 || x >= C) continue;
                        if (board[y][x] != '*') board[y][x]++;
                    }
                }
            }
        }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) printf("%c", board[i][j] + (board[i][j] == '*' ? 0 : 2));
            printf("\n");
        }
    }
}
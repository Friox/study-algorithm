#include <stdio.h>
char board[50][51] = { 0 };
char whiteBoard[8][9] = {
    { "WBWBWBWB" },
    { "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" }
};

char blackBoard[8][9] = {
    { "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" },
    { "WBWBWBWB" },
    { "BWBWBWBW" },
    { "WBWBWBWB" }
};

int min(int a, int b) {return (a < b ? a : b);}

int whiteDiff(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i + y][j + x] != whiteBoard[i][j]) cnt++;
        }
    }
    return cnt;
}

int blackDiff(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i + y][j + x] != blackBoard[i][j]) cnt++;
        }
    }
    return cnt;
}

int main() {
    int N, M, result = 2501, mMin;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", board[i]);
    }
    for (int y = 0; y <= N - 8; y++) {
        for (int x = 0; x <= M - 8; x++) {
            mMin = min(whiteDiff(x, y), blackDiff(x, y));
            result = (mMin < result ? mMin : result);
        }
    }
    printf("%d", result);
}
#include <cstdio>
int arr[9][9], blanks[81][2], cnt = 0;
bool row[9][10], col[9][10], square[9][10];
inline int gidx(int y, int x) { return (y / 3) * 3 + (x / 3); }

bool step(int idx) {
    if (idx == cnt) return true;
    int y = blanks[idx][0];
    int x = blanks[idx][1];
    int s = gidx(y, x);
    for (int i = 1; i <= 9; i++) {
        if (!row[y][i] && !col[x][i] && !square[s][i]) {
            arr[y][x] = i; row[y][i] = 1; col[x][i] = 1; square[s][i] = 1;
            if (step(idx + 1)) return true;
            arr[y][x] = 0; row[y][i] = 0; col[x][i] = 0; square[s][i] = 0;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0) { blanks[cnt][0] = i; blanks[cnt++][1] = j; }
            else {
                int s = gidx(i, j);
                row[i][arr[i][j]] = 1; col[j][arr[i][j]] = 1; square[s][arr[i][j]] = 1;
            }
        }
    }
    step(0);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d%c", arr[i][j], j == 8 ? '\n' : ' ');
        }
    }
}
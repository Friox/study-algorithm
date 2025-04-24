#include <ios>
int main() {
    int n, m, sTable[1002][1002] = { 0 }, a;
    int x1, y1, x2, y2;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &a);
            sTable[i + 1][j + 1] = sTable[i][j + 1] + sTable[i + 1][j] - sTable[i][j] + a;
        }
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        printf("%d\n", sTable[y2][x2] - sTable[y1 - 1][x2] - sTable[y2][x1 - 1] + sTable[y1 - 1][x1 - 1]);
    }
}
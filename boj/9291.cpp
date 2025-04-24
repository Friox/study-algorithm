#include <stdio.h>
int numList[9];
void resetNumList() { for (int i = 0; i < 9; i++) numList[i] = 0; }
int checkCorrect() {
    for (int i = 0; i < 9; i++) if (numList[i] != 1) return 0;
    return 1;
}
int checkSudoku(int matrix[][9]) {
    int xC = 0, yC = 0, zC = 0, flag = 0;
    for (int i = 0; i < 9; i++) {
        resetNumList();
        for (int j = 0; j < 9; j++) numList[matrix[i][j] - 1]++;
        if (checkCorrect() != 1) return 0;
    }
    for (int i = 0; i < 9; i++) {
        resetNumList();
        for (int j = 0; j < 9; j++) numList[matrix[j][i] - 1]++;
        if (checkCorrect() != 1) return 0;
    }
    for (int i = 0; i <= 6; i += 3) {
        for (int j = 0; j <= 6; j += 3) {
            resetNumList();
            for (int k = i; k < i + 3; k++) {
                for (int l = j; l < j + 3; l++) {
                    numList[matrix[k][l] - 1]++;
                }
            }
            if (checkCorrect() != 1) return 0;
        }
    }
    return 1;
}

int main() {
    int T, sudoku[9][9];
    scanf("%d", &T);
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        printf("Case %d: %s", t + 1, (checkSudoku(sudoku) != 1 ? "INCORRECT" : "CORRECT"));
        if (t != T - 1) printf("\n");
    }
}
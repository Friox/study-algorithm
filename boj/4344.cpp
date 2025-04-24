#include <stdio.h>
#include <math.h>

int main() {
    int C, student[1000];
    scanf("%d", &C);
    for (int i = 0; i < C; i++) {
        double avarage;
        int N, sum = 0, overCnt = 0;
        scanf("%d", &N);
        for (int j = 0; j < N; j++) {
            scanf("%d", &student[j]);
            sum += student[j];
        }
        avarage = (double)sum / N;
        for (int j = 0; j < N; j++) {
            if ((double)student[j] > avarage) overCnt++;
        }
        printf("%.3lf%%", round(((double)overCnt / N) * 100000) / 1000);
        if (i != C - 1) printf("\n");
    }
}
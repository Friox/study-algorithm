#include <stdio.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int H, W, N, cnt = 0, flag = 0;
        scanf("%d %d %d", &H, &W, &N);
        for (int j = 1; j <= W; j++) {
            for (int k = 1; k <= H; k++) {
                if (++cnt == N) {
                    printf("%d%02d", k, j);
                    if (i != tc - 1) printf("\n");
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
    }   
}
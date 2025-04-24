#include <stdio.h>

int main() {
    int N, score[1000] = { 0 }, high = -1, low = 1001;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &score[i]);
        high = (score[i] > high ? score[i] : high);
        low = (score[i] < low ? score[i] : low);
    }
    printf("%d", high - low);
}
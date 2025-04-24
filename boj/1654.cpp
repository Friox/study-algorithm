#include <stdio.h>

int main() {
    int a, b;
    long long L = 1, M, H = -1, cnt, length = 0;
    scanf("%d %d", &a, &b);
    long long lan[a] = { 0 };
    for (int i = 0; i < a; i++) {
        scanf("%lld", &lan[i]);
        H = H < lan[i] ? lan[i] : H;
    }
    while (L <= H) {
        cnt = 0;
        M = (L + H) / 2;
        for (int i = 0; i < a; i++) cnt += lan[i] / M;
        // printf("Length : %lld, Count : %lld, L : %lld, H : %lld\n", M, cnt, L, H);
        if (cnt < b) H = M - 1;
        else {
            L = M + 1;
            length = length < M ? M : length;
        }
    }
    printf("%lld", length);
}
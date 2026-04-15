#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using std::vector;
int main() {
    int R, C, T, p[2] = { 0 }, cnt = 0;
    scanf("%d %d %d", &R, &C, &T);
    int m = R * C, d[4] = { -C, C, -1, 1 };
    vector<int> a(m), b(m), *aP = &a, *bP = &b;
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
        if (a[i] == -1) p[p[0] ? 1 : 0] = i / C;
    }
    while (T--) {
        std::fill(bP->begin(), bP->end(), 0);

        // 확산
        for (int i = 0; i < m; i++) {
            int v = (*aP)[i];
            if (v > 0) {
                int cY = i / C, cX = i % C, vv = v / 5, cnt = 0;
                for (int j = 0; j < 4; j++) {
                    int n = i + d[j];
                    int nY = n / C, nX = n % C;
                    if (n < 0 || n >= R * C || abs(cX - nX) > 1 || (*aP)[n] == -1) continue;
                    cnt++;
                    (*bP)[n] += vv;
                }
                (*bP)[i] += (*aP)[i] - vv * cnt;
            } else if (v == -1) (*bP)[i] = -1;
        }

        // 정화
        for (int i = p[0] - 1; i > 0; i--) (*bP)[i * C] = (*bP)[(i - 1) * C];
        for (int i = 0; i < C - 1; i++) (*bP)[i] = (*bP)[i + 1];
        for (int i = 0; i < p[0]; i++) (*bP)[i * C + (C - 1)] = (*bP)[(i + 1) * C + (C - 1)];
        for (int i = C - 1; i >= 2; i--) (*bP)[p[0] * C + i] = (*bP)[p[0] * C + (i - 1)];
        (*bP)[p[0] * C + 1] = 0;

        for (int i = p[1] + 1; i < R - 1; i++) (*bP)[i * C] = (*bP)[(i + 1) * C];
        for (int i = 0; i < C - 1; i++) (*bP)[(R - 1) * C + i] = (*bP)[(R - 1) * C + (i + 1)];
        for (int i = R - 1; i > p[1]; i--) (*bP)[i * C + (C - 1)] = (*bP)[(i - 1) * C + (C - 1)];
        for (int i = C - 1; i >= 2; i--) (*bP)[p[1] * C + i] = (*bP)[p[1] * C + (i - 1)];
        (*bP)[p[1] * C + 1] = 0;

        vector<int>* tmp = bP; bP = aP; aP = tmp;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int v = (*aP)[i * C + j];
            if (v > 0) cnt += v;
            printf("%d ", (*aP)[i * C + j]);
        }
        printf("\n");
    }
    printf("%d", cnt);
}
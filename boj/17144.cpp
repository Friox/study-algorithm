#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>
using std::vector;
int main() {
    int R, C, T, p[2] = { 0 }, cnt = 0;
    scanf("%d %d %d", &R, &C, &T);
    int m = R * C, d[4] = { -C, C, -1, 1 };
    int dy[2][4] = {{ -1, 0, 1, 0 }, { 1, 0, -1, 0 }}, dx[4] = { 0, 1, 0, -1 };
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
        for (int k = 0; k < 2; k++) {
            int y = p[k] + dy[k][0], x = 0, dir = 0;
            while (dir < 4) {
                int nY = y + dy[k][dir], nX = x + dx[dir];
                if (k == 0 && (nY < 0 || nY > p[k] || nX < 0 || nX >= C)) { dir++; continue; }
                if (k == 1 && (nY < p[k] || nY >= R || nX < 0 || nX >= C)) { dir++; continue; }
                if (nY == p[k] && nX == 0) break;
                (*bP)[y * C + x] = (*bP)[nY * C + nX];
                y = nY, x = nX;
            }
            (*bP)[p[k] * C + 1] = 0;
        }

        vector<int>* tmp = bP; bP = aP; aP = tmp;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int v = (*aP)[i * C + j];
            if (v > 0) cnt += v;
        }
    }
    printf("%d", cnt);
}
#include <ios>
struct Shark { int y, x, alive, speed, direction, size; };
int main() {
    int R, C, M, r, c, s, d, z, p = 0, S = 0;
    Shark sharks[10000];
    Shark* cur[101][101] = { 0 };
    scanf("%d %d %d", &R, &C, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d %d", &r, &c, &s, &d, &z);
        sharks[i] = {r, c, 1, s, d, z};
        cur[r][c] = &sharks[i];
    }
    while (++p <= C) {
        for (int i = 1; i <= R; i++) {
            if (cur[i][p] && cur[i][p]->alive == 1) {
                S += cur[i][p]->size;
                cur[i][p]->alive = 0;
                break;
            }
        }
        for (int i = 0; i < M; i++) cur[sharks[i].y][sharks[i].x] = 0;
        for (int i = 0; i < M; i++) {
            if (!sharks[i].alive) continue;
            Shark& shark = sharks[i];
            int& dir = sharks[i].direction;
            int ts = shark.speed, tx = shark.x, ty = shark.y, step;
            ts %= (((dir <= 2) ? R : C) - 1) * 2;
            while (ts) {
                if (dir == 1) {
                    step = (ty - 1 < ts) ? ty - 1 : ts;
                    ty -= step;
                    if (ty == 1) dir = 2;
                } else if (dir == 2) {
                    step = (R - ty < ts) ? R - ty : ts;
                    if (ts < step) step = ts;
                    ty += step;
                    if (ty == R) dir = 1;
                } else if (dir == 3) {
                    step = (C - tx < ts) ? C - tx : ts;
                    if (ts < step) step = ts;
                    tx += step;
                    if (tx == C) dir = 4;
                } else {
                    step = (tx - 1 < ts) ? tx - 1 : ts;
                    if (ts < step) step = ts;
                    tx -= step;
                    if (tx == 1) dir = 3;
                }
                ts -= step;
            }
            if (cur[ty][tx]) {
                if (shark.size < cur[ty][tx]->size) shark.alive = 0;
                else {
                    cur[ty][tx]->alive = 0;
                    shark.x = tx;
                    shark.y = ty;
                    cur[ty][tx] = &shark;
                }
            } else {
                shark.x = tx;
                shark.y = ty;
                cur[ty][tx] = &shark;
            }
        }
    }
    printf("%d", S);
}
#include <ios>
#include <queue>

struct Pos { int y, x; };
struct Di { int time; char dir; };

int main() {
    Pos w[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int N, K, L, m[101][101] = { 0 }, y, x, t, dir = 0, sec = 0;
    char d;
    Pos head = {1, 1}; m[1][1] = 2;
    std::queue<Di> di;
    std::deque<Pos> pi;
    pi.push_back(head);
    scanf("%d %d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &y, &x);
        m[y][x] = 1;
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        scanf("%d %c", &t, &d);
        di.push({t, d});
    }
    for (;sec <= 10000; sec++) {
        if (di.front().time == sec) {
            if (di.front().dir == 'L') dir--;
            else dir++;
            if (dir == -1) dir = 3;
            else if (dir == 4) dir = 0;
            di.pop();
        }
        Pos next = {head.y + w[dir].y, head.x + w[dir].x};
        if (next.y > N || next.y <= 0 || next.x > N || next.x <= 0 || m[next.y][next.x] == 2) break;
        pi.push_back(next);
        if (m[next.y][next.x] == 0) {
            m[pi.front().y][pi.front().x] = 0;
            pi.pop_front();
        }
        m[next.y][next.x] = 2;
        head = next;
    }
    printf("%d", sec + 1);
}
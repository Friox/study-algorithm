#include <stdio.h>
#include <algorithm>
using namespace std;
struct point{ int x, y; };
bool compare(const point &p1, const point &p2) {
    if (p1.y == p2.y) {
        return p1.x < p2.x;
    } else {
        return p1.y < p2.y;
    }
}

int main() {
    struct point mPoint[100000] = { 0 };
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) scanf("%d %d", &mPoint[i].x, &mPoint[i].y);
    sort(mPoint, mPoint + a, compare);
    for (int i = 0; i < a; i++) {
        printf("%d %d", mPoint[i].x, mPoint[i].y);
        if (i != a - 1) printf("\n");
    }
}
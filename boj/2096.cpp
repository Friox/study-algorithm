#include <ios>
#include <algorithm>
using std::max, std::min;
int main() {
    int n, a, b, c, dpMax[3], dpMin[3];
    int t1, t2, t3;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        if (!i) {
            dpMax[0] = a; dpMax[1] = b; dpMax[2] = c;
            dpMin[0] = a; dpMin[1] = b; dpMin[2] = c;
        } else {
            t1 = max(dpMax[0], dpMax[1]);
            t2 = max({dpMax[0], dpMax[1], dpMax[2]});
            t3 = max(dpMax[1], dpMax[2]);
            dpMax[0] = t1 + a; dpMax[1] = t2 + b; dpMax[2] = t3 + c;
            t1 = min(dpMin[0], dpMin[1]);
            t2 = min({dpMin[0], dpMin[1], dpMin[2]});
            t3 = min(dpMin[1], dpMin[2]);
            dpMin[0] = t1 + a; dpMin[1] = t2 + b; dpMin[2] = t3 + c;
        }
    }
    printf("%d %d", max({dpMax[0], dpMax[1], dpMax[2]}), min({dpMin[0], dpMin[1], dpMin[2]}));
}
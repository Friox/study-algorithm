#include <ios>
#include <algorithm>
using std::pair;
bool comp(pair<int, int> &a, pair<int, int> &b) { return a.second > b.second; }

int main() {
    int N, d, w, s = 0, l[1001] = { 0 };
    pair<int, int> v[1000];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &d, &w);
        v[i] = {d, w};
    }
    std::sort(v, v + N, comp);
    for (int i = 0; i < N; i++) {
        for (int j = v[i].first; j > 0; j--) {
            if (l[j] == 0) {
                l[j] = v[i].second;
                break;
            }
        }
    }
    for (int i = 1; i < 1001; i++) s += l[i];
    printf("%d", s);
}
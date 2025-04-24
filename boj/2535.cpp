#include <ios>
#include <vector>
#include <algorithm>
int main() {
    int n, a, b, c, cnt1[101] = { 0, }, cnt2 = 0;
    std::vector<std::pair<int, std::pair<int, int>>> v;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        v.push_back({c, { a, b }});
    }
    std::sort(v.begin(), v.end(), std::greater<std::pair<int, std::pair<int, int>>>());
    for (int i = 0; i < n; ++i) {
        if (!(cnt1[v[i].second.first] >= 2)) {
            ++cnt2;
            ++cnt1[v[i].second.first];
            printf("%d %d\n", v[i].second.first, v[i].second.second);
            if (cnt2 == 3) break;
        }
    }
}
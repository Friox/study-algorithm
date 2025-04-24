#include <cstdio>
#include <set>
int main() {
    int N, M, K, s, e, last, cnt = 1;
    std::set<int> r[2001];
    bool v[2001] = { 0 };
    scanf("%d %d %d", &N, &M, &K);
    last = K;
    v[K] = true;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &s, &e);
        r[s].insert(e); r[e].insert(s);
    }
    while (true) {
        int next = 0;
        if (!r[last].empty()) {
            for (const int& el: r[last]) {
                if (!v[el]) {
                    next = el;
                    break;
                }
            }
        }
        if (next == 0) break;
        cnt++;
        v[next] = true;
        last = next;
    }
    printf("%d %d", cnt, last);
}
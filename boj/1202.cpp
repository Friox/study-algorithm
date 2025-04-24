#include <ios>
#include <vector>
#include <queue>
#include <algorithm>

int main() {
    std::pair<int, int> gem[300001];
    int N, K, idx = 0, bag[300001] = { 0 };
    std::priority_queue<int, std::vector<int>, std::less<int>> pq;
    long long sum = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; ++i) scanf("%d %d", &gem[i].first, &gem[i].second);
    for (int i = 0; i < K; ++i) scanf("%d", &bag[i]);
    std::sort(gem, gem + N);
    std::sort(bag, bag + K);
    for (int i = 0; i < K; ++i) {
        while (idx < N && bag[i] >= gem[idx].first) pq.push(gem[idx++].second);
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    printf("%lld", sum);
}
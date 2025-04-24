#include <ios>
#include <queue>

int main() {
    int N, s, arr[100000] = { 0 }, ans = 0, cnt = 0;
    std::priority_queue<int> pq;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &s);
        pq.push(-s);
    }
    while (!pq.empty() && (cnt != N - 1)) {
        int n1 = -pq.top(); pq.pop();
        int n2 = -pq.top(); pq.pop();
        ans += (n1 + n2);
        pq.push(-(n1 + n2));
        cnt++;
    }
    printf("%d", ans);
}
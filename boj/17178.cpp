#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
int main() {
    int N, idx = 0;
    std::queue<int> pool;
    std::stack<int> waiting;
    std::vector<int> check;
    scanf("%d", &N);
    for (int i = 0; i < N * 5; i++) {
        char a;
        int b;
        scanf(" %c-%d", &a, &b);
        int n = a * 10000 + b;
        pool.push(n);
        check.push_back(n);
    }
    std::sort(check.begin(), check.end());
    while (idx < N * 5) {
        if (!waiting.empty() && waiting.top() == check[idx]) {
            waiting.pop();
            idx++;
        } else if (!pool.empty() && pool.front() == check[idx]) {
            pool.pop();
            idx++;
        } else if (!pool.empty()) {
            while (!pool.empty() && pool.front() != check[idx]) {
                waiting.push(pool.front());
                pool.pop();
            }
        } else break;
    }
    printf("%s", idx == N * 5 ? "GOOD" : "BAD");
}
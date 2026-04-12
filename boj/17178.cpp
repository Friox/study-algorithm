#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
std::string cvt(int n) {
    return std::string(1, n / 10000) + "-" + std::to_string(n % 10000);
}
int main() {
    int N, idx = 0;
    std::queue<int> pool;
    std::stack<int> waiting;
    std::vector<int> check;
    scanf("%d", &N);
    int cnt = N * 5;
    for (int i = 0; i < cnt; i++) {
        char a;
        int b;
        scanf(" %c-%d", &a, &b);
        int n = a * 10000 + b;
        // printf("%d\n", n);
        pool.push(n);
        check.push_back(n);
    }
    while (idx < cnt) {
        if (!waiting.empty() && waiting.top() == check[idx]) {
            printf("대기열에서 %s 발견\n", cvt(waiting.top()).c_str());
            waiting.pop();
            idx++;
            continue;
        }
        if (!pool.empty() && pool.front() == check[idx]) {
            printf("풀에서 %s 발견\n", cvt(pool.front()).c_str());
            pool.pop();
            idx++;
            continue;
        }
        if (!pool.empty()) {
            while (!pool.empty() && pool.front() != check[idx]) {
                printf("%s 를 대기열로 이동\n", cvt(pool.front()).c_str());
                waiting.push(pool.front());
                pool.pop();
            }
            continue;
        }
        break;
    }
    printf("%s", check.empty() ? "GOOD" : "BAD");
}

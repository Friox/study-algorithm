#include <stdio.h>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    int K, N, sum = 0;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &N);
        if (N) s.push(N);
        else s.pop();
    }
    while (!s.empty()) {
        sum += s.top();
        s.pop();
    }
    printf("%d", sum);
}
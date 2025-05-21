#include <cstdio>

int main() {
    int N;
    long long sum, result, C;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &C);
        if (i == 0) { sum = C; result = C; continue; }
        sum = (C > sum + C) ? C : sum + C;
        if (sum > result) result = sum; 
    }
    printf("%lld", result > 0 ? result : 0);
}
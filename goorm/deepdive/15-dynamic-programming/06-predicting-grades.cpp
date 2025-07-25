#include <cstdio>

const int MOD = 1000000;

int main() {
    int N;
    scanf("%d", &N);

    // a0: B 사용 X, 연속된 C가 0개인 경우
    // a1: B 사용 X, 연속된 C가 1개인 경우
    // a2: B 사용 X, 연속된 C가 2개인 경우
    // b0: B 사용 O, 연속된 C가 0개인 경우
    // b1: B 사용 O, 연속된 C가 1개인 경우
    // b2: B 사용 O, 연속된 C가 2개인 경우
    long long a0 = 1, a1 = 0, a2 = 0;
    long long b0 = 0, b1 = 0, b2 = 0;

    for (int i = 1; i <= N; i++) {
        long long na0 = (a0 + a1 + a2) % MOD; // A 선택, B 사용 X, C 연속 0개
        long long nb0 = (b0 + b1 + b2) % MOD; // A 선택, B 사용 O, C 연속 0개
        nb0 = (nb0 + (a0 + a1 + a2)) % MOD; // B 선택
        long long na1 = a0 % MOD; // C 선택, B 사용 X, C 연속 1개
        long long nb1 = b0 % MOD; // C 선택, B 사용 O, C 연속 1개
        long long na2 = a1 % MOD; // C 선택, B 사용 X, C 연속 2개
        long long nb2 = b1 % MOD; // C 선택, B 사용 O, C 연속 2개
        a0 = na0; a1 = na1; a2 = na2;
        b0 = nb0; b1 = nb1; b2 = nb2;
    }

    long long ans = (a0 + a1 + a2 + b0 + b1 + b2) % MOD;
    printf("%lld", ans);
}

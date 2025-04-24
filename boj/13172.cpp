#include <ios>
#include <numeric>
long long MOD = 1'000'000'007;
long long process(long long x, long long y) {
    // 모듈러연산
    if (y == 1) return x;
    if (y % 2 == 1) return x * process(x, y - 1) % MOD;
    long long t = process(x, y / 2);
    return t * t % MOD;
}

int main() {
    long long M, N, S, res = 0;
    scanf("%lld", &M);
    while (M--) {
        scanf("%lld %lld", &N, &S);
        long long D = std::gcd(N, S);
        N /= D;
        S /= D;
        res += S * process(N, MOD - 2) % MOD;
        res %= MOD;
    }
    printf("%lld", res);
}
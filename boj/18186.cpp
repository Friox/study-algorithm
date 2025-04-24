#include <ios>
long long n, buy[1000001], tmp, b, c, cost;
int main() {
    scanf("%lld %lld %lld", &n, &b, &c);
    for (int i = 1; i <= n; ++i) scanf("%lld", &buy[i]);
    if (b < c) for (int i = 1; i <= n; ++i) cost += b * buy[i];
    else {
        for (int i = 1; i <= n; ++i) {
            if (buy[i + 1] > buy[i + 2]) {
                tmp = std::min(buy[i], buy[i + 1] - buy[i + 2]);
                cost += (b + c) * tmp;
                buy[i] -= tmp;
                buy[i + 1] -= tmp;
                tmp = std::min(buy[i], std::min(buy[i + 1], buy[i + 2]));
                cost += (b + 2 * c) * tmp;
                buy[i] -= tmp;
                buy[i + 1] -= tmp;
                buy[i + 2] -= tmp;
            } else {
                tmp = std::min(buy[i], std::min(buy[i + 1], buy[i + 2]));
                cost += (b + 2 * c) * tmp;
                buy[i] -= tmp;
                buy[i + 1] -= tmp;
                buy[i + 2] -= tmp;
                tmp = std::min(buy[i], buy[i + 1]);
                cost += (b + c) * tmp;
                buy[i] -= tmp;
                buy[i + 1] -= tmp;
            }
            cost += b * buy[i];
        }
    }
    printf("%lld", cost);
}
#include <cstdio>
#include <functional>
#include <vector>
#include <algorithm>
using std::vector, std::pair, std::sort, std::greater;
int main() {
    // 과일은 자른다고 가치가 떨어지지 않는다.
    // 조각낸 과일 당 포만감이 큰 과일조각을 계속 구매하면된다.
    vector<pair<long long, long long>> v;
    int N;
    long long K, P, C, res = 0;
    scanf("%d %lld", &N, &K);
    for (int i = 0; i < N; i++) {
        scanf("%lld %lld", &P, &C); // 과일가격과 포만감을 입력받고,
        v.push_back({ C / P, P }); // (한조각당 포만감, 조각개수) 형태로 저장
    }
    // 한조각당 포만감을 내림차순으로 정렬.
    sort(v.begin(), v.end(), greater<pair<long long, long long>>());
    for (int i = 0; i < N; i++) {
        // 온전한 과일의 가격과 현재 남은 돈을 비교하여,
        // 온전한 과일을 살 수 있으면 그걸 구매하고
        // 만약 살 수 없으면 현재 남은 돈에 맞게 조각을 구매한다.
        long long price = v[i].first;
        long long count = v[i].second;
        // 살 수 있는 최대 조각개수를 구함
        long long willBuy = count < K ? count : K;
        K -= willBuy;
        res += price * willBuy;
    }
    printf("%lld", res);
}
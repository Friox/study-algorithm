#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector, std::pair, std::sort, std::greater;
int main() {
    // 과일은 자른다고 가치가 떨어지지 않는다.
    // 조각낸 과일 당 포만감이 큰 과일조각을 계속 구매하면된다.
    vector<pair<long long, long long>> v; // 조각당 포만감과 개수를 저장할 배열
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
        // 가치가 큰 과일조각부터 먹어봄
        while (1) {
            res += v[i].first; // 결과에 한 조각당 포만감 누적
            K--; // 한 조각 먹었으니 돈 -1
            v[i].second--; // 남아있는 조각개수 -1
            // 만약 과일의 조각개수가 없거나, 돈이 없다면 탈출
            if (v[i].second == 0 || K == 0) break;
        }
        // 한 과일을 다먹었을때 돈이 없어도 탈출
        if (K == 0) break;
    }
    printf("%lld", res);
}
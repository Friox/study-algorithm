#include <cstdio>
#include <cmath>
#include <vector>

int main() {
    /*
    [문제 이해]
    처음에 딱 봤을 때 문제가 잘 이해되지 않아 이해 과정을 정리해봤습니다.
    어떠한 경우에도 체력이 감소하지 않는 갑옷을 판타스틱 갑옷이라고 한다
    나의 갑옷 고유값을 A, 상대 무기의 고유값을 W 라고 했을때,
    (A > W), (A % W == 0) 이 두 조건을 모두 만족하지 않는다면 체력은 감소하지 않는다.
    이 논리적 조건의 형태를 변환하면, (A <= W) or (A % W != 0) 이 된다.
    풀어서 설명하면 판타스틱 갑옷의 경우
    판타스틱 갑옷 고유값이 상대 무기의 고유값 보다 같거나 작으면 체력은 감소하지 않고,
    판타스틱 갑옷 고유값이 상대 무기의 고유값 보다 크더라도
    갑옷 고유값을 무기 고유값으로 나눈 나머지가 0이 아니면 체력은 감소하지 않는다.
    즉, A가 1과 자신 이외의 수로 나누어지지 않는 소수인지 판단하는 간단한 문제다.
    소수 판정 여부를 재사용해야하니 에라토스테네스의 체를 이용한다.
    */

    int N, A[5000] = { 0 }, max = 0;
    bool isFantastic = true;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if (A[i] > max) max = A[i];
    }
    std::vector<bool> filter(max + 1);
    int limit = (int)sqrt(max);
    for (int i = 2; i <= limit; i++) {
        if (filter[i]) continue;
        for (int j = i; j <= max; j += i) {
            if (j != i) filter[j] = true;
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%s\n", filter[A[i]] ? "No" : "Yes");
    }
}
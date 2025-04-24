#include <cstdio>
#include <vector>

int main() {
    int N, M, x, Q;
    long long cnt = 0; // 목재량 변수
    char D;
    scanf("%d %d %d", &N, &M, &x);
    std::vector<int> trees(N + 1); // x를 인덱스로 사용하기 위해 +1
    for (int i = 1; i <= N; i++) scanf("%d", &trees[i]);
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {

        /*
        벌목 과정을 거칠때 마다 모든 나무의 높이를 1씩 증가하는것을 반복하는건 조금 무리다.
        나무 높이에 벌목과정 횟수를 더하여 불필요한 반복을 없앤다.
        */

        // i번 지난 후의 나무높이를 trees[x] + i로 생각하기
        if (trees[x] + i >= M) {
            // 만약 현재위치의 나무가 M 보다 클 경우
            cnt += trees[x] + i; // 나무를 벌목하고
            trees[x] -= (trees[x] + i); // 현재 높이에서 자란 나무의 높이를 빼줌.
        }
        scanf(" %c", &D);

        // 클램프 적용
        if (D == 'L') x = (x == 1) ? N : x - 1;
        else if (D == 'R') x = (x == N) ? 1 : x + 1;
    }

    // 출력
    printf("%lld", cnt);
}
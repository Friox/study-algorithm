#include <cstdio>
#include <vector>

int main() {
    int N, M, x, Q, cnt = 0;
    char D;
    scanf("%d %d %d", &N, &M, &x);
    std::vector<int> trees(N + 1); // x를 인덱스로 사용하기 위해 +1
    for (int i = 1; i <= N; i++) scanf("%d", &trees[i]);
    scanf("%d", &Q);
    while (Q--) {
        if (trees[x] >= M) {
            // 만약 현재위치의 나무가 M 보다 클 경우
            cnt += trees[x]; // 나무를 벌목하고
            trees[x] = 0; // 높이를 0으로 초기화
        }
        scanf(" %c", &D);

        // 클램프 적용
        if (D == 'L') x = (x == 1) ? N : x - 1;
        else if (D == 'R') x = (x == N) ? 1 : x + 1;
        for (int &tree : trees) ++tree; // 모든 나무의 높이 1씩 증가
    }

    // 출력
    printf("%d", cnt);
}
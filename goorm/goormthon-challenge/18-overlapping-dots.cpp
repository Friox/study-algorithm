#include <cstdio>
#include <vector>
using std::vector;
struct YX {
    // Y, X 좌표를 다루기 편하게 하고
    // board에서 사용될때는 한칸의 자료형으로 사용됨. (1)
    // 지나가는 선의 개수를 담고있음. (y: 세로선, x: 가로선)
    int y, x;
    YX& operator+=(const YX &t) {
        // 연산자 재정의 (2)
        y += t.y;
        x += t.x;
        return *this;
    }
    // 한칸 당 교점의 개수가 최대 25억개. int 타입 불가능
    long long multiply() { return y * (long long)x; } // 교점 계산
};

int main() {
    YX UDLR['Z']; // 문자를 인덱스로 하여 배열 생성. ('Z' == 90), 메모리 낭비 감수
    UDLR['U'] = { -1, 0 }; UDLR['D'] = { 1, 0 };
    UDLR['L'] = { 0, -1 }; UDLR['R'] = { 0, 1 };
    int N, M, a, b;
    char d;
    // 교점은 최대 25억개 나올 수 있음 (5만칸 x 5만칸)
    long long res = 0; // int 대신 long long 사용
    scanf("%d %d", &N, &M);
    vector<vector<YX>> board(N + 1, vector<YX>(N + 1)); // 2차원 보드 생성 (1)
    while (M--) {
        scanf("%d %d %c", &a, &b, &d);
        YX cur = { a, b }; // 현재 위치
        YX tmp = { 0, 1 }; // 현재 위치에 덮어쓸 값. (L, R 기준 x 증가)
        if (d == 'U' || d == 'D') tmp = { 1, 0 }; // (U, D 기준 y 증가)
        while (!(cur.y < 1) && !(cur.y > N) && !(cur.x < 1) && !(cur.x > N)) {
            // 경계를 벗어날때까지 현재 위치에 덮어쓰고 벡터이용하여 현재위치 변경
            board[cur.y][cur.x] += tmp;
            cur += UDLR[d]; // 원래 사용자 지정 자료형끼리 계산은 안되지만 재정의해서 가능. (2)
        }
    }
    // 이 시점에서는 보드에 각 칸별 지나가는 선의 개수가 담겨있음.
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            // 하나씩 확인하면서 교점을 구하고 누적. (교점: 세로선 X 가로선)
            res += board[i][j].multiply();
        }
    }
    printf("%lld", res); // 결과 출력
}
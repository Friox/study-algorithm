#include <cstdio>
#include <vector>
#define OFFSET 2000
using std::vector;
struct Pos { int y, x; };

int main() {
    // 문자에 따른 좌표 벡터를 다루기 쉽게 공간복잡도를 살짝 포기함
    // 86칸중 4칸을 제외한 나머지를 낭비하게 됨
    // U == 85
    Pos dir['U' + 1]; // Pos dir[86], 인덱스: 0 ~ 85
    dir['L'] = { +0, -1 }; dir['R'] = { +0, +1 }; // dir[76], dir[82]
    dir['U'] = { +1, +0 }; dir['D'] = { -1, +0 }; // dir[85], dir[68]

    // rx: robot x, ry: robot y
    // ix: input x, iy: input y
    // nx: next x, ny: next y
    int rx, ry, ix, iy, nx, ny, N, Q;
    char cmd; // command
    scanf("%d %d %d", &rx, &ry, &N); // 로봇좌표와 N 입력

    // -좌표를 처리하기 위해 시작 좌표를 0으로 만드는 오프셋을 적용
    // 2000을 더하면 0 ~ 4000으로 생각할 수 있음
    rx += OFFSET; ry += OFFSET;
    vector<vector<bool>> arr(4001, vector<bool>(4001));
    for (int i = 0; i < N; i++) {
        // 웅덩이 좌표 입력 및 체크
        scanf("%d %d", &ix, &iy);
        arr[iy + OFFSET][ix + OFFSET] = true;
    }
    scanf("%d", &Q);
    while (Q--) {
        // 현재 좌표를 이용하여 임시로 사용할 다음 좌표를 구한 뒤,
        // 다음 좌표를 이용하여 배열을 확인한 뒤 웅덩이가 아니면 현재 좌표를 다음 좌표로 갱신함.
        scanf(" %c", &cmd); // 커맨드 입력
        nx = rx + dir[cmd].x; // 다음 좌표의 X
        ny = ry + dir[cmd].y; // 다음 좌표의 Y

        // 만약 다음 좌표가 웅덩이가 아니면 
        if (!arr[ny][nx]) { rx = nx; ry = ny; }
    }

    // 출력시에는 실제 좌표를 출력해야하니 오프셋을 반영하여 출력
    printf("%d %d", rx - OFFSET, ry - OFFSET);
}
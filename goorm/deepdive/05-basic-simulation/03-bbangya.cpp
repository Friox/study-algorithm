#include <cstdio>

int main() {
    int N, enemy, damage = 1;
    long long fire = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &enemy);

        /*
        damage: 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, ...
        데미지를 1 증가시키며 단순히 반복하면 시간초과.
        1, 2, 3, 4가 반복되고 있으니 10의 데미지를 줄때 4번을 쏜것으로 판단한다.
        남은 체력에 10을 나눴을때 몫을 이용하여 한꺼번에 데미지를 입힌다.
        그리고 남은값은 반복으로 처리.
        */
        
        fire += (enemy / 10) * 4; // 사격횟수는 (적 체력 / 10) * 4
        enemy %= 10; // 체력은 체력을 10으로 나눈 나머지로 설정한다.

        // 남은 체력에 대해 반복해서 데미지를 입힌다
        while (enemy > 0) {
            enemy -= damage;
            // 전위증감식, 데미지 1 증가했을때 4를 넘어가면 1로 초기화
            if (++damage > 4) damage = 1;
            fire++;
        }
    }
    printf("%lld", fire);
}
#include <cstdio>
#include <cstdlib>
#include <vector>
using std::vector;

int main() {
    /*
    Alice의 카드는 비교를 위해 배열에 저장해야하지만,
    Bob의 카드는 입력 즉시 Alice의 카드와 비교하면 되기때문에 배열이 필요없다.
    */
    int N, bob, aliceScore = 0, bobScore = 0; // N, bob의 카드, 점수 변수 선언
    scanf("%d", &N); // N 입력
    vector<int> alice(N); // Alice 카드를 저장할 배열
    for (int i = 0; i < N; i++) scanf("%d", &alice[i]); // alice 카드 입력
    for (int i = 0; i < N; i++) {
        // bob 카드 입력받으면서
        scanf("%d", &bob);
        if (alice[i] == bob) {
            // 서로 공격력이 같은 경우 양쪽 점수 증가
            ++aliceScore;
            ++bobScore;
        } else {
            // 서로 공격력이 다른 경우
            if (abs(alice[i] - bob) == 7) {
                // 공격력의 차이가 정확히 7점인 경우
                aliceScore += (alice[i] < bob ? 3 : -1);
                bobScore += (bob < alice[i] ? 3 : -1);
            } else {
                // 7점 차이가 아닌 경우
                aliceScore += (alice[i] > bob ? 2 : 0);
                bobScore += (bob > alice[i] ? 2 : 0);
            }
        }
    }

    // 출력
    printf("%d %d", aliceScore, bobScore);
}
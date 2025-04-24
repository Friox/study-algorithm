#include <ios>

int main() {
    int N, M, a, b, res = 0;
    bool dag[501][501] = { 0 };
    scanf("%d %d", &N, &M);
    
    // INPUT
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        dag[a][b] = 1;
    }

    // 플로이드
    // 학생만큼 반복
    for (int s = 1; s <= N; s++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                // 만약 상호간 갈 수 있다면
                if (dag[i][s] && dag[s][j]) dag[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (dag[i][j] || dag[j][i]) cnt++;
        }
        if (cnt == N - 1) res++;
    }
    
    printf("%d", res);
}
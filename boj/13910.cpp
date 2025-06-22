#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<int> wok(M);
    for (int i = 0; i < M; i++) scanf("%d", &wok[i]);
    vector<int> dp(N + 1, __INT_MAX__);
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < M; j++) {
            int w = wok[j];
            if (w > i) continue;
            if (dp[i - w] != __INT_MAX__) dp[i] = min(dp[i], dp[i - w] + 1);
            for (int k = j + 1; k < M; k++) {
                int nw = wok[k];
                if (nw + w > i || dp[i - (nw + w)] == __INT_MAX__) continue;
                dp[i] = min(dp[i], dp[i - (nw + w)] + 1);
            }
        }
    }
    printf("%d", dp[N] == __INT_MAX__ ? -1 : dp[N]);
}
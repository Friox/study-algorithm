#include <cstdio>
#include <vector>
using namespace std;

int dfs(int n, vector<vector<int>>& v, vector<bool>& visited, vector<int>& dp) {
    int temp = 1;
    if (dp[n] != 0) return dp[n];
    visited[n] = true;
    for (int i = 0; i < v[n].size(); i++) {
        int next = v[n][i];
        if (visited[next]) continue;
        temp += dfs(next, v, visited, dp);
    }
    dp[n] = temp;
    return temp;
}

int main() {
    int N, R, Q, s, e;
    scanf("%d %d %d", &N, &R, &Q);
    vector<vector<int>> v(N + 1, vector<int>());
    vector<int> dp(N + 1);
    vector<bool> visited(N + 1);
    for (int i = 0; i < N - 1; i++) {
        scanf("%d %d", &s, &e);
        v[s].push_back(e);
        v[e].push_back(s);
    }
    dp[R] = dfs(R, v, visited, dp);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &s);
        printf("%d\n", dp[s]);
    }
}
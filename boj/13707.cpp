#include <cstdio>
int main() {
    int n, k, arr[5001][5001] = { 1, };;
    scanf("%d %d", &n, &k);
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            arr[i][j] = (arr[i][j - 1] + (i ? arr[i - 1][j] : 0)) % 1000000000;
        }
    }
    printf("%d", arr[n][k]);
}
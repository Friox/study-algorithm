#include <ios>
#include <vector>
using std::vector, std::max;
int main() {
    int t, n, a;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<vector<int>> v1(2, vector<int>(n + 1));
        vector<vector<int>> v2(2, vector<int>(n + 1, 0));
        for (int i = 0; i < 2; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a);
                v1[i][j] = a;
            }
        }
        v2[0][1] = v1[0][1]; v2[1][1] = v1[1][1];
        for (int i = 2; i <= n; ++i) {
            v2[0][i] = max(v2[1][i - 2], v2[1][i - 1]) + v1[0][i];
            v2[1][i] = max(v2[0][i - 2], v2[0][i - 1]) + v1[1][i];
        }
        printf("%d\n", max(v2[0][n], v2[1][n]));
    }
}
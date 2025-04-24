#include <ios>
#include <vector>
int main() {
    std::vector<char> res;
    int i, j;
    char str1[1002] = { 0 }, str2[1002] = { 0 };
    short dp[1001][1001] = { 0, };
    scanf("%s %s", str1, str2);
    for (i = 0; str1[i]; ++i) {
        for (j = 0; str2[j]; ++j) {
            if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = (dp[i + 1][j] > dp[i][j + 1]) ? dp[i + 1][j] : dp[i][j + 1];
        }
    }
    printf("%d", dp[i][j]);
    
    // Reverse
    if (dp[i][j]) {
        printf("\n");
        while (dp[i][j]) {
            if (str1[i - 1] == str2[j - 1]) {
                res.push_back(str1[i - 1]);
                i--; j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) i--;
            else j--;
        }
        for (int k = res.size() - 1; k >= 0; k--) printf("%c", res[k]);
    }
}
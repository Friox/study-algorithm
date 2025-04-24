#include <iostream>
int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    int s1len = str1.length(), s2len = str2.length();
    short dp[1001][1001] = { 0, };
    for (int i = 0; i < s1len; ++i) {
        for (int j = 0; j < s2len; ++j) {
            if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
            else dp[i + 1][j + 1] = (dp[i + 1][j] > dp[i][j + 1]) ? dp[i + 1][j] : dp[i][j + 1];
        }
    }
    for (int a = 0; a <= s1len; a++) {
        for (int b = 0; b <= s2len; b++) {
            printf("%3d%c", dp[a][b], b == s2len ? '\n' : '\t');
        }
    }
    printf("%d", dp[s1len][s2len]);
}
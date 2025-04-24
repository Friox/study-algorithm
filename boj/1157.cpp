#include <stdio.h>
#include <string.h>

int main() {
    char str[1000001] = { 0 };
    int cnt[26] = { 0 }, max = 0, maxCnt = 0;
    scanf("%s", str);
    int length = strlen(str);
    for (int i = 0; i < length; i++) cnt[str[i] > 'Z' ? str[i] - 97 : str[i] - 65]++;
    for (int i = 0; i < 26; i++) if (cnt[i] > max) max = cnt[i];
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == max) {
            if (maxCnt >= 1) {
                str[0] = '?';
                break;
            }
            str[0] = i + 65;
            maxCnt++;
        }
    }
    printf("%c", str[0]);
}
#include <stdio.h>
#include <string.h>

int main() {
    char a[50][51] = { 0 };
    char result[51] = { 0 };
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) scanf("%s", a[i]);
    if (c == 1) strcpy(result, a[0]);
    else {
        int length = strlen(a[0]);
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < c - 1; j++) {
                if (a[j][i] != a[j + 1][i]) {
                    result[i] = '?';
                    break;
                }
                result[i] = a[j][i];
            }
        }
    }
    printf("%s", result);
}
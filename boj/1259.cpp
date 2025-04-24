#include <stdio.h>
#include <string.h>

int palindrome(char *str);

int main() {
    char num[6] = { 0 };
    int a, cnt = 0;
    while (1) {
        for (int i = 0; i < 6; i++) num[i] = 0;
        scanf("%d", &a);
        if (!a) break;
        else {
            if (cnt++) printf("\n");
            sprintf(num, "%d", a);
            if (palindrome(num)) printf("yes");
            else printf("no");
        }
    }
}

int palindrome(char *str) {
    int length = strlen(str);
    int startIndex = 0;
    int endIndex = length - 1;
    int halfIndex = length / 2;
    for (int i = startIndex, j = endIndex; i < halfIndex; i++, j--) {
        if (str[i] != str[j]) return 0;
    }
    return 1;
}
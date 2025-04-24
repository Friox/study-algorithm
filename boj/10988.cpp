#include <stdio.h>
#include <string.h>

int palindrome(char *str);

int main() {
    char str[101] = {};
    scanf("%s", str);
    printf("%d", palindrome(str));
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
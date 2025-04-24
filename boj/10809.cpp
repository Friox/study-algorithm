#include <stdio.h>
#include <string.h>

int main() {
    char str[101] = { 0 };
    int index[26] = { 0 };
    scanf("%s", str);
    int length = strlen(str);
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < length; j++) {
            if (str[j] == 97 + i) {
                index[i] = j;
                break;
            } else if (j == length - 1) index[i] = -1;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("%d", index[i]);
        if (i != 25) printf(" ");
    }
}
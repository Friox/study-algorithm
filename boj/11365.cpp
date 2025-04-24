#include <stdio.h>
#include <string.h>

int main() {
    int len, cnt = 0;
    char str[501] = { 0 };
    while (1) {
        scanf(" %[^\n]s", str);
        if (!strcmp("END", str)) break;
        else {
            len = strlen(str);
            if (cnt++) printf("\n");
            for (int i = len - 1; i >= 0; i--) printf("%c", str[i]);
        }
    }
}
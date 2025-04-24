#include <stdio.h>
#include <string.h>

int main() {
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        int loop;
        char str[21] = { 0 };
        scanf("%d %s", &loop, str);
        for (int j = 0; j < strlen(str); j++) {
            for (int k = 0; k < loop; k++) {
                printf("%c", str[j]);
            }
        }
        if (i != tc - 1) printf("\n");
    }
}
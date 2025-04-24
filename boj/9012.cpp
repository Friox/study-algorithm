#include <stdio.h>
#include <string.h>

int stack[50] = { 0 }, stackIndex = -1;

int main() {
    char ps[51] = { 0 };
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        scanf("%s", ps);
        int length = strlen(ps);
        for (int j = 0; j < length; j++) {
            char chr = ps[j];
            if (stackIndex == -1) {
                if (chr == ')') {
                    printf("NO");
                    // printf(" (First ')', index : %d)", j);
                    if (i != tc - 1) printf("\n");
                    break;
                } else {
                    stack[++stackIndex] = (chr == '(' ? 1 : -1);
                }
            } else {
                stack[++stackIndex] = (chr == '(' ? 1 : -1);
                if (stack[stackIndex] + stack[stackIndex - 1] == 0) {
                    stack[stackIndex] = 0;
                    stack[stackIndex - 1] = 0;
                    stackIndex -= 2;
                }
            }
            if (j == length - 1) {
                if (stackIndex == -1) {
                    printf("YES");
                } else {
                    printf("NO");
                }
                if (i != tc - 1) {
                    printf("\n");
                }
                stackIndex = -1;
            }
        }
    }
}
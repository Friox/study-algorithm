#include <stdio.h>
#include <string.h>

int main() {
    int cnt = 0;
    char a[1000001] = { 0 };
    scanf("%[^\n]", a);
    char *ptr = strtok(a, " ");
    while (ptr != NULL) {
        cnt++;
        ptr = strtok(NULL, " ");
    }
    printf("%d", cnt);
}
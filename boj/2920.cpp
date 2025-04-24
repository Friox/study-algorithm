#include <stdio.h>
#include <string.h>

int main() {
    char a[17] = { 0 };
    scanf("%[^\n]", a);
    if (!strcmp(a, "1 2 3 4 5 6 7 8")) printf("ascending");
    else if (!strcmp(a, "8 7 6 5 4 3 2 1")) printf("descending");
    else printf("mixed");
}
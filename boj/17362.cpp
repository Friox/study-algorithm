#include <stdio.h>
int main() {
    int N, table[8] = { 2, 1, 2, 3, 4, 5, 4, 3 };
    scanf("%d", &N);
    printf("%d", table[N % 8]);
}
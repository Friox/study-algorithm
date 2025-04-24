#include <stdio.h>

int main() {
    int N, n, arr[100] = { 0 }, cnt = 0;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &n);
        if (arr[n - 1] == 0) arr[n - 1] = 1;
        else cnt++;
    }
    printf("%d", cnt);
}
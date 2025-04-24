#include <stdio.h>
#include <algorithm>

int main() {
    int n, num, cache[100001] = {0}, max = -1001;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
		scanf("%d", &num);
        cache[i] = (cache[i - 1] > 0 ? cache[i - 1] : 0) + num;
        if (cache[i] > max) max = cache[i];
    }
    printf("%d", max);
}
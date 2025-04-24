#include <stdio.h>

int main() {
    int n, k, maxSum = -101, sum = 0, arr[100000] = {0}, j;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    for (j = 0; j < k; j++) sum += arr[j];
    maxSum = sum;
    for (int i = 0; i < n - k; i++, j++) {
        sum -= arr[i];
        sum += arr[j];
        maxSum = (sum > maxSum ? sum : maxSum);
    }
    printf("%d", maxSum);
}
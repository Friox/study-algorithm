#include <stdio.h>

int fact(int start, int end) {
    int result = 1;
    for (int i = start; i >= end; i--) result *= i;
    return result;
}

int main() {
    int N, K, num[2] = { 0 };
    scanf("%d %d", &N, &K);
    num[0] = (K > N - K ? K : N - K);
    num[1] = (K > N - K ? N - K : K);
    printf("%d", fact(N, num[0] + 1) / fact(num[1], 1));
}
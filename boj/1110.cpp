#include <stdio.h>

int main() {
    int num, N, cnt = 0;
    scanf("%d", &num);
	N = num;
	do {
		N = (N % 10) * 10 + ((N / 10) + (N % 10)) % 10;
		cnt++;
	} while (num != N);
    printf("%d", cnt);
}
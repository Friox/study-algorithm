#include <cstdio>

int main() {
    // 소인수를 이용한 간단한 문제.
    // 2와 5의 조합 하나가 0하나를 만든다.
    // 둘중에 작은 값이 0의 개수.
    int N, two = 0, five = 0, ten = 0;
    scanf("%d", &N);
    for (int i = 2; N / i > 0; i *= 2) two += N / i;
    for (int i = 5; N / i > 0; i *= 5) five += N / i;
    printf("%d", two < five ? two : five);
}
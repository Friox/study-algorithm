#include <ios>

void test() {
    long long A, B, mask, sum = 0;
    scanf("%lld %lld", &A, &B);
    for (long long i = A; i <= B; i++) {
        mask = 9007199254740992;
        for (int j = 0; j < 54; j++) {
            if (i & mask) printf("1");
            else printf("0");
            mask = mask >> 1;
        }
        printf("\n");
    }
    // printf("%lld", sum);
}

void real() {
    long long A, B, mask, sum = 0;
    scanf("%lld %lld", &A, &B);
    for (long long i = A; i <= B; i++) {
        mask = 9007199254740992;
        for (int j = 0; j < 54; j++) {
            if (i & mask) sum++;
            mask = mask >> 1;
        }
    }
    printf("%lld", sum);
}

int main() {
    test();
}
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int N, num[1001] = {0}, sum = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &num[i]);
    sort(num, num + N);
    for (int i = 0; i < N; i++) {
        if (sum < num[i]) break;
        sum += num[i];
    }
    printf("%d", sum + 1);
}
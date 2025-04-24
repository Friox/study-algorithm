#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int N, time[1000] = { 0 }, sum = 0, result = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &time[i]);
    sort(time, time + N);
    for (int i = 0; i < N; i++) {
        sum += time[i];
        result += sum;
    }
    printf("%d", result);
}
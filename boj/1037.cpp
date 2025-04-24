#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int arr[50] = { 0 };
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    sort(arr, arr + N);
    printf("%d", arr[0] * arr[N - 1]);
}
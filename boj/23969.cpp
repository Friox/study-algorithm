#include <cstdio>

void solve(int arr[], int N, int K, int &cnt) {
    int tmp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                if (++cnt == K) {
                    return;
                }
            }
        }
    }
}

int main() {
    int arr[10000] = { 0 }, N, K, cnt = 0;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    solve(arr, N, K, cnt);
    if (cnt == K) for (int i = 0; i < N; i++) printf("%d ", arr[i]);
    else printf("-1");
}
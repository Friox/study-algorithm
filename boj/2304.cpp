#include <cstdio>

int main() {
    int arr[1001] = { 0 }, N, L, H;
    int start = 1001, end = 0;
    int pivotIdx, pivotHeight = 0;
    int tmp, result = 0;

    // 입력 및 값 세팅
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &L, &H);
        arr[L] = H;
        if (L < start) start = L;
        if (L > end) end = L;
        if (H > pivotHeight) {
            pivotIdx = L;
            pivotHeight = H;
        }
    }

    // 왼쪽
    tmp = 0;
    for (int i = start; i < pivotIdx; i++) {
        tmp = (tmp > arr[i]) ? tmp : arr[i];
        result += tmp;
    }

    // 오른쪽
    tmp = 0;
    for (int i = end; i > pivotIdx; i--) {
        tmp = (tmp > arr[i]) ? tmp : arr[i];
        result += tmp;
    }

    // 중심
    result += pivotHeight;

    printf("%d", result);
}
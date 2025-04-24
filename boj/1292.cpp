#include <stdio.h>
void makeSeq(int arr[1000], int end) {
    int cnt = 1;
    for (int i = 2;;i++) {
        for (int j = 0; j < i; j++, cnt++) {
            if (cnt == end) return;
            arr[cnt] = arr[cnt - 1] + i;
        }
    }
}

int main() {
    int A, B, arr[1000] = { 1, 0 };
    scanf("%d %d", &A, &B);
    makeSeq(arr, B);
    printf("%d", arr[B - 1] - (A - 2 < 0 ? 0 : arr[A - 2]));
}
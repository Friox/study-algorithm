#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int N, L, mBreak[1001], tape[1001] = { 0 }, cnt = 0;
    scanf("%d %d", &N, &L);
    for (int i = 0; i < N; i++) scanf("%d", &mBreak[i]);
    sort(mBreak, mBreak + N);
    for (int i = 0; i < N; i++) {
        if (!tape[mBreak[i]]) {
            for (int j = mBreak[i]; j < min(mBreak[i] + L, 1001); j++) tape[j] = 1;
            cnt++;
        }
    }
    printf("%d", cnt);
}
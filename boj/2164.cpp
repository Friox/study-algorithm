#include <stdio.h>
int start = 0, end;
int getStart() {return start;}
int updateStart(int length) {
    int temp = start;
    ++start %= length;
    return temp;
}
int updateEnd(int length) {
    ++end %= length;
    return end;
}

int main() {
    int N, card[500001] = { 0 }, cnt = 0;
    scanf("%d", &N);
    cnt = N;
    end = N - 1;
    for (int i = 0; i < N; i++) card[i] = i + 1;
    while (!(cnt == 1 && start == end)) {
        card[updateStart(N)] = 0;
        card[updateEnd(N)] = card[getStart()];
        card[updateStart(N)] = 0;
        --cnt;
    }
    printf("%d", card[start]);
}
#include <cstdio>
int main() {
    int students[100001] = {};
    bool check[100001] = {}, flag = false;
    int N, M, X, Y;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) students[i] = i;
    while (M--) {
        scanf("%d %d", &X, &Y);
        students[X]++;
        students[Y]--;
    }
    for (int i = 1; i <= N; i++) {
        if (check[students[i]]) {
            flag = true;
            break;
        }
        check[students[i]] = true;
    }
    if (flag) printf("-1");
    else for (int i = 1; i <= N; i++) printf("%d ", students[i]);
}
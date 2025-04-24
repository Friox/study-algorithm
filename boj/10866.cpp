#include <stdio.h>
#include <deque>
using namespace std;
int main() {
    deque<int> d;
    char command[11] = { 0 };
    int N, param, tmp = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        tmp = 1;
        scanf("%s", command);
        if (command[1] == 'u') {
            tmp = 0;
            scanf("%d", &param);
            if (command[5] == 'f') d.push_front(param);
            else d.push_back(param);
        } else if (command[1] == 'o') {
            if (d.empty()) printf("-1");
            else {
                if (command[4] == 'f') {
                    printf("%d", d.front());
                    d.pop_front();
                } else {
                    printf("%d", d.back());
                    d.pop_back();
                }
            }
        } else if (command[0] == 's') printf("%ld", d.size());
        else if (command[0] == 'e') printf("%d", (d.empty()));
        else if (command[0] == 'f') {
            if (d.empty()) printf("-1");
            else printf("%d", d.front());
        } else if (command[0] == 'b') {
            if (d.empty()) printf("-1");
            else printf("%d", d.back());
        }
        if ((tmp == 1) && (i != N - 1)) printf("\n");
    }
}
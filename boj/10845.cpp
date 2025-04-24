#include <stdio.h>
int q[10000] = { 0 }, fIdx = 0, eIdx = -1, cnt = 0;
void push(int x) {
    q[++eIdx] = x;
    cnt++;
}
int pop() {
    if (cnt == 0) return -1;
    else {
        int res;
        res = q[fIdx++];
        cnt--;
        return res;
    }
}
int size() { return cnt; }
int empty() { return cnt == 0 ? 1 : 0; }
int front() { return cnt == 0 ? -1 : q[fIdx]; }
int back() { return cnt == 0 ? -1 : q[eIdx]; }
int main() {
    char cmd[6] = { 0 };
    int N, cmdT;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        cmdT = 1;
        scanf("%s", cmd);
        if (cmd[1] == 'u') {
            // push
            int num;
            scanf("%d", &num);
            push(num);
            cmdT = 0;
        } else if (cmd[1] == 'o') printf("%d", pop());
        else if (cmd[1] == 'i') printf("%d", size());
        else if (cmd[1] == 'm') printf("%d", empty());
        else if (cmd[1] == 'r') printf("%d", front());
        else printf("%d", back());
        if (cmdT && i != N - 1) printf("\n");
    }
}
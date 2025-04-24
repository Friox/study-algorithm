#include <stdio.h>
#include <string.h>
int stack[10000] = { 0 }, stackIndex = -1;
void push(int a) {if (stackIndex < 9999) stack[++stackIndex] = a;}
int pop() {return (stackIndex == -1 ? -1 : stack[stackIndex--]);}
int size() {return stackIndex + 1;}
int empty() {return (stackIndex == -1 ? 1 : 0);}
int top() {return (stackIndex == -1 ? -1 : stack[stackIndex]);}
int main() {
    char command[5] = { 0 };
    int tc, param;
    scanf("%d", &tc);
    for (int i = 0; i < tc; i++) {
        scanf("%s", command);
        if (!strcmp(command, "push")) {
            scanf("%d", &param);
            push(param);
        } else if (!strcmp(command, "pop")) {
            printf("%d\n", pop());
        } else if (!strcmp(command, "size")) {
            printf("%d\n", size());
        } else if (!strcmp(command, "empty")) {
            printf("%d\n", empty());
        } else {
            printf("%d\n", top());
        }
    }
}
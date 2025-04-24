#include <stdio.h>

char convertChar(char ch) {
    switch (ch) {
        case '-': return '|';
        case '|': return '-';
        case '/': return '\\';
        case '\\' :return '/';
        case '^': return '<';
        case '<': return 'v';
        case 'v': return '>';
        case '>': return '^';
    }
    return ch;
} 

int main() {
    char str[100][101] = { 0 };
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) scanf("%s", str[i]);
    for (int i = M - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            printf("%c", convertChar(str[j][i]));
        }
        if (i != 0) printf("\n");
    }
}
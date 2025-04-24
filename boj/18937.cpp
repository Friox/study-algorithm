#include <ios>
int main() {
    int n, a, r = 0;
    char king[10];
    scanf("%d", &n);
    while (n--) { scanf("%d", &a); r ^= (a - 2); }
    scanf("%s", king);
    printf("%s", r ? king : ((king[0] == 'W') ? "Blackking" : "Whiteking"));
}
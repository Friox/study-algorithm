#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int a[1000000], c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) scanf("%d", &a[i]);
    sort(a, a + c);
    printf("%d %d", a[0], a[c - 1]);
}
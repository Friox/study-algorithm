#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int a[10];
    int c;
    scanf("%d", &c);
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < 10; j++) {
            scanf("%d", &a[j]);
        }
        sort(a, a + 10);
        printf("%d\n", a[7]);
    }
}
#include <stdio.h>

int main() {
    int N, a = 0, b = 0, i;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &i);
        if (i) a++;
        else b++;
    }
    if (a > b) printf("Junhee is cute!");
    else printf("Junhee is not cute!");
}
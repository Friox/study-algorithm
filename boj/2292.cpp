#include <stdio.h>

int polygon(int num);

int main() {
    int num;
    scanf("%d", &num);
    printf("%d", polygon(num));
}

int polygon(int num) {
    int i;
    if (num == 1) return 1;
    else {
        for (i = 1; !(num >= (3 * (i - 1)) * i + 2 && num <= 3 * (i - 1) * i + 6 * i + 1); i++) {}
        return i + 1;
    }
}
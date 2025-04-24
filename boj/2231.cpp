#include <stdio.h>
#include <string.h>

int extSum(int a) {
    char strNum[8] = { 0 };
    int length, result = 0;
    sprintf(strNum, "%d", a);
    length = strlen(strNum);
    result += a;
    for (int i = 0; i < length; i++) result += strNum[i] - '0';
    return result;
}

int main() {
    int a, result = 0;
    scanf("%d", &a);
    for (int i = (a < 54 ? 0 : a - 54); i < a + 54; i++) {
        if (a == extSum(i)) {
            result = i;
            break;
        }
    }
    if (result) {
        printf("%d", result);
    } else {
        printf("%d", 0);
    }
}
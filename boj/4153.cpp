#include <stdio.h>
#include <algorithm>
using namespace std;
int pow(int a) { return a * a; }

int main() {
    int num[3] = { 0 }, cnt = 0;
    while (scanf("%d %d %d", &num[0], &num[1], &num[2]) != EOF) {
        if (num[0] == 0 && num[1] == 0 && num[2] == 0) return 0;
        else {
            if (cnt++ != 0) printf("\n");
            if (num[0] == 0 || num[1] == 0 || num[2] == 0) {
                printf("wrong");
            } else {
                sort(num, num + 3);
                if (pow(num[2]) == pow(num[1]) + pow(num[0])) printf("right");
                else printf("wrong");
            }
        }
    }
}
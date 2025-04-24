#include <stdio.h>
#include <vector>
using namespace std;

int main() {
    vector<int> num(20000001);
    //int num[20000001] = { 0 };
    int M, n, cnt = 0;
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &n);
        num[n + 10000000] = 1;
    }
    scanf("%d", &M);
    while (M--) {
        scanf("%d", &n);
        if (cnt++) printf(" ");
        printf("%d", num[n + 10000000]);
    }
}
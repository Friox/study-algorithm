#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int getIndex(int n) { return n + 4000; }
int main() {
    int a[8001] = { 0 }, b[500000] = { 0 };
    int N, nIndex, num, min = 4001, max = -4001, sum = 0, maxFreq = 0, maxNum = 0, flag = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        nIndex = getIndex(num);
        a[nIndex]++;
        b[i] = num;
        max = (num > max ? num : max);
        min = (num < min ? num : min);
        sum += num;
    }
    sort(b, b + N);
    for (int i = getIndex(min); i <= getIndex(max); i++) {
        if (a[i] > maxFreq) {
            maxNum = i - 4000;
            maxFreq = a[i];
            flag++;
        }
    }
    if (flag) {
        flag = 0;
        for (int i = getIndex(min); i <= getIndex(max); i++) {
            if (a[i] == maxFreq) {
                if (flag) {
                    maxNum = i - 4000;
                    break;
                }
                flag++;
            }
        }
    }

    double avrg = (double)sum / N;
    printf("%.f\n", round(avrg) == -0 ? 0 : round(avrg)); // ok
    printf("%d\n", b[N / 2]); // ok
    printf("%d\n", maxNum);
    printf("%d", max - min); // ok
}
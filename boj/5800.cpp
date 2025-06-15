#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int K;
    scanf("%d", &K);
    for (int tc = 0; tc < K; tc++) {
        int N, min = 101, max = -1, max2 = 0;
        scanf("%d", &N);
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
            if (arr[i] > max) max = arr[i];
            if (arr[i] < min) min = arr[i];
        }
        sort(arr.begin(), arr.end());
        for (int i = 1; i < N; i++) {
            int temp = arr[i] - arr[i - 1];
            if (temp > max2) max2 = temp;
        }
        printf("Class %d\n", tc + 1);
        printf("Max %d, Min %d, Largest gap %d\n", max, min, max2);
    }
}
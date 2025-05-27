// 중복체크만 잘 하면 되는 문제

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    while (true) {
        scanf("%d %d", &N, &M);
        if (N == 0 && M == 0) break;
        int result = 0;
        vector<int> a(N), b(M);
        for (int i = 0; i < N; i++) scanf("%d", &a[i]);
        for (int i = 0; i < M; i++) scanf("%d", &b[i]);
        sort(a.begin(), a.end());
        for (int n : b) if (binary_search(a.begin(), a.end(), n)) result++;
        printf("%d\n", result);
    }
}
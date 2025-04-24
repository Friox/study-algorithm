#include <ios>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> v1, v2;
    int N, X;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        v1.push_back(X);
        v2.push_back(X);
    }
    std::sort(v1.begin(), v1.end());
    v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
    for (int val: v2) {
        printf("%ld ", std::lower_bound(v1.begin(), v1.end(), val) - v1.begin());
    }
}
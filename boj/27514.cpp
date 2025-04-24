#include <ios>
#include <vector>
#include <algorithm>
using std::vector, std::sort;
int main() {
    vector<long long> v;
    int n;
    long long a;
    bool flag = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", &a);
        if (a) v.push_back(a);
    }
    if (n == 1) printf("%lld", v[0]);
    else if (!v.size()) printf("0");
    else if (v.size() == 1) printf("%lld", v[0]);
    else {
        while (1) {
            sort(v.begin(), v.end(), std::greater<>());
            while (!v.back()) v.pop_back();
            for (int i = 0; i < v.size(); ++i) {
                printf("%lld ", v[i]);
            }
            printf("\n");
            flag = 1;
            for (int i = 0; i < v.size() - 1; ++i) {
                if (v[i] == v[i + 1]) {
                    v[i] *= 2;
                    v[i + 1] = 0;
                    flag = 0;
                }
            }
            if (flag) break;
        }
        printf("%lld", v[0]);
    }
}
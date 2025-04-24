#include <ios>
#include <vector>
std::vector<int> a, ans;

int search(int n) {
    int l = 0, r = ans.size() - 1, m;
    while (l < r) {
        m = l + (r - l) / 2;
        if (ans[m] >= n) r = m;
        else l = m + 1;
    }
    return r;
}

int main() {
	int n, t, idx;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        a.push_back(t);
    }
    ans.push_back(a.front());
    for (int i = 1; i < n; i++) {
        if (a[i] > ans.back()) ans.push_back(a[i]);
        else {
            idx = search(a[i]);
            ans[idx] = a[i];
        }
    }
    printf("%ld", ans.size());
}
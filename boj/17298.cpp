#include <stdio.h>
#include <stack>
int main() {
	int n, a[1000000], b[1000000];
	std::stack<int> s;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && s.top() <= a[i]) s.pop();
        if (s.empty()) b[i] = -1;
        else b[i] = s.top();
        s.push(a[i]);
    }
    for (int i = 0; i < n; ++i) printf("%d ", b[i]);
}
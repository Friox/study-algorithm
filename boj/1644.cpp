#include <stdio.h>
#include <vector>
std::vector<int> v;
std::vector<bool> p;
int main() {
	int n, s = 0, e = 0, r = 0, max;
	scanf("%d", &n);
	p.resize(n + 1);
	for (int i = 2; i <= n; ++i) if (!p[i]) {
		v.push_back(i);
		for (int j = i * 2; j <= n; j += i) p[j] = 1;
	}
	max = v.size();
	if (max) {
		int sum = v[s];
		while (e <= max && s <= e) {
			if (sum < n) sum += v[++e];
			else {
				if (sum == n) ++r;
				sum -= v[s++];
			}
		}
	}
	printf("%d", r);
}
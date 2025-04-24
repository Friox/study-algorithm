#include <stdio.h>
#include <utility>
#include <algorithm>
typedef long long ll;
bool compare(std::pair<int, int> a, std::pair<int, int> b) { return a.first < b.first; }
int main() {
	int n, d, l = 0, r = 0;
	ll tmp = 0, res = 0;
	std::pair<int, int> na[100000];
	scanf("%d %d", &n, &d);
	for (int i = 0; i < n; ++i) scanf("%d %d", &na[i].first, &na[i].second);
	sort(na, na + n, compare);
	while (l <= r && r < n) {
		if (na[r].first - na[l].first < d) tmp += na[r++].second;
		else tmp -= na[l++].second;
		res = std::max(res, tmp);
	}
	printf("%lld", res);
}
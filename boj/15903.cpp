#include <stdio.h>
#include <queue>

int main() {
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> q;
	int n, m, num;
	long long a, b, sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		q.push(num);
	}
	while (m--) {
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		q.push(a + b);
		q.push(a + b);
	}
	while (!q.empty()) {
		sum += q.top();
		q.pop();
	}
	printf("%lld", sum);
}
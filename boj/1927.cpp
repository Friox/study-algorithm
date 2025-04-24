#include <stdio.h>
#include <queue>
#include <vector>
int main() {
	int n, x;
	std::priority_queue<int, std::vector<int>, std::greater<>> pQ;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		if (x) pQ.push(x);
		else {
			printf("%d\n", (pQ.empty() ? 0 : pQ.top()));
			if (!pQ.empty()) pQ.pop();
		}
	}
}
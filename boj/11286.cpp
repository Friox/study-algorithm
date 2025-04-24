#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pQ;
priority_queue<int> nQ;
void ppQ() { printf("%d\n", pQ.top()); pQ.pop(); }
void pnQ() { printf("%d\n", nQ.top()); nQ.pop(); }
int main() {
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		if (n > 0) pQ.push(n);
		else if (n < 0) nQ.push(n);
		else {
			if (pQ.empty() && nQ.empty()) printf("0\n");
			else if (!pQ.empty() && nQ.empty()) ppQ();
			else if (pQ.empty() && !nQ.empty()) pnQ();
			else {
				if (pQ.top() < -nQ.top()) ppQ();
				else pnQ();
			}
		}
	}
}
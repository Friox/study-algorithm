#include <stdio.h>
#include <queue>

int main() {
	int n;
	std::queue<int> myQueue;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) myQueue.push(i);
	while (myQueue.size() != 1) {
		printf("%d ", myQueue.front());
		myQueue.pop();
		int a = myQueue.front();
		myQueue.pop();
		myQueue.push(a);
	}
	printf("%d", myQueue.front());
}
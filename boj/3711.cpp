#include <stdio.h>
#include <map>

int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		bool flag;
		int g, m = 0;
		scanf("%d", &g);
		int arr[300] = { 0 };
		for (int i = 0; i < g; ++i) {
			scanf("%d", &arr[i]);
		}
		while (1) {
			flag = true;
			++m;
			std::map<int, bool> a;
			for (int i = 0; i < g; ++i) {
				if (a.find(arr[i] % m) != a.end()) {
					flag = false;
					break;
				}
				a.insert({arr[i] % m, 1});
			}
			if (flag) {
				printf("%d\n", m);
				break;
			}
		}
	}
}
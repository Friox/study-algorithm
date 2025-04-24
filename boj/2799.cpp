#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::string apart[501];
	int m, n, blind[5] = { 0 };
	std::cin >> m >> n;
	for (int i = 0; i < 5 * m + 1; i++) std::cin >> apart[i];
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			int yPoint = i * 5 + 1;
			int xPoint = j * 5 + 1;
			int count = 0;
			for (int k = 0; k < 4; k++) {
				if (apart[yPoint + k][xPoint] == '*') count++;
			}
			blind[count]++;
		}
	}
	for (int i = 0; i < 5; i++) std::cout << blind[i] << ' ';
}
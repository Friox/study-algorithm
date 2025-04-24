#include <iostream>
#include <string>
#include <algorithm>

int main() {
	std::string n;
	std::cin >> n;
	std::sort(n.rbegin(), n.rend());
	if (n[n.length() - 1] != '0') std::cout << -1;
	else {
		int end = n.length() - 1, sum = 0;
		for (int i = 0; i < end; i++) sum += n[i] - 48;
		if (sum % 3 == 0) std::cout << n;
		else std::cout << -1;
	}
}
#include <ios>
#include <iostream>
#include <utility>
#include <vector>
int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::string str;
	while (1) {
		int n;
		double len, max = 0;
		std::cin >> n;
		if (!n) break;
		std::vector<std::pair<std::string, double>> v;
		std::vector<std::string> s;
		for (int i = 0; i < n; ++i) {
			std::cin >> str >> len;
			if (len > max) max = len;
			v.push_back({str, len});
		}
		for (int i = 0; i < n; ++i) {
			if (v[i].second == max) {
				s.push_back(v[i].first);
			}
		}
		for (int i = 0; i < s.size(); ++i) {
			std::cout << s[i] << ' ';
		}
		std::cout << '\n';
	}
}
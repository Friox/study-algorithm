#include <iostream>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int n, cnt = 0;
	std::string str;
	std::map<std::string, bool> person;
	std::cin >> n;
	while (n--) {
		std::cin >> str;
		if (str == "ENTER") {
			person = std::map<std::string, bool>();
		} else {
			if (person.find(str) == person.end()) {
				person.insert({str, true});
				cnt++;
			}
		}
	}
	std::cout << cnt;
}
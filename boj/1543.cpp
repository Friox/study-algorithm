#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	int idx = 0, len, cnt = 0;
	std::string doc, word;
	getline(std::cin, doc);
	getline(std::cin, word);
	len = word.length();
	while ((idx = doc.find(word, idx)) != std::string::npos) {
		idx += len;
		cnt++;
	}
	std::cout << cnt;
}
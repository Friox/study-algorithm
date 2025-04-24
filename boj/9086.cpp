#include <iostream>
int main() {
	int t;
	std::string str;
	scanf("%d", &t);
	while (t--) {
		std::cin >> str;
		printf("%c%c\n", str[0], str[str.length() - 1]);
	}
}
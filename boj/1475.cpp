#include <iostream>
#include <string>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	std::string str;
	bool flag = false;
	int len, set = 1, cnt[10], code, extra = 2;
	for (int i = 0; i < 10; i++) cnt[i] = 1;
	std::cin >> str;
	len = str.length();
	for (int i = 0; i < len; i++) {
		code = str[i] - 48;
		if (code == 6 || code == 9) {
			if (--extra < 0) flag = true;
		} else if (--cnt[code] < 0) flag = true;
		if (flag) {
			for (int j = 0; j < 10; j++) cnt[j]++;
			extra += 2;
			set++;
			flag = false;
		}
	}
	std::cout << set;
}
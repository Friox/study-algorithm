#include <iostream>
#include <string>

int main() {
	std::string str[8] = {
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
		"WBWBWBWB",
		"BWBWBWBW",
	};
	int cnt = 0;
	std::string input[8];
	for (int i = 0; i < 8; i++) std::cin >> input[i];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (str[i][j] == 'W' && input[i][j] == 'F') cnt++;
		}
	}
	printf("%d", cnt);
}
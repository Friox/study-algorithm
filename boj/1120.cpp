#include <iostream>

int main() {
	int lenA, lenB, diff, min = 51;
	std::string A, B;
	std::cin >> A >> B;
	lenA = A.length();
	lenB = B.length();
	diff = lenB - lenA;
	for (int i = 0; i < diff + 1; i++) {
		int cnt = 0;
		for (int j = 0; j < lenA; j++) {
			if (A[j] != B[i + j]) cnt++;
		}
		if (cnt < min) min = cnt;
	}
	std::cout << min;
}
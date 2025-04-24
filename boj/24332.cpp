#include <iostream>
#include <string>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
    bool check[123];
    for (int i = 0; i < 123; i++) check[i] = false;
    int startIndex = 0, endIndex, length = 0, resultStart = 0, resultEnd = 0, resultLength = 0;
    std::string input;
    std::cin >> input;
    length = input.length();
    for (endIndex = 0; endIndex < length; endIndex++) {
		// 끝 인덱스 하나씩 늘림
        if (check[input[endIndex]]) {
			// 만약 중복된 문자면
			do {
				// 시작 인덱스 하나씩 올리되
				if (input[startIndex] == input[endIndex]) {
					// 중복된 문자면 반복문 탈출
					startIndex++;
					break;
				} else {
					// 중복된 문자가 사라지지 않으면
					// 사라진 문자 중복체크배열에서 제거
					check[input[startIndex]] = false;
					startIndex++;
				}
			} while (startIndex < endIndex);
        } else {
			// 중복되지 않은 문자면
			// 중복체크배열에 체크
            check[input[endIndex]] = true;
        }
		// 길이체크후 후처리
		if (endIndex - startIndex + 1 >= resultLength) {
            resultLength = endIndex - startIndex + 1;
            resultStart = startIndex;
            resultEnd = endIndex;
        }
    }
    printf("%d %d\n%s", resultLength, resultStart, input.substr(resultStart, resultLength).c_str());
}
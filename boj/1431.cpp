#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using std::string;

int ctoi(char ch) {
    // 2번 조건을 처리하기 위한 함수
    // 문자를 숫자로 변환하여 반환하는데, 숫자가 아니라면 0을 반환함.
    int tmp = ch - '0';
    if (tmp < 0 || tmp > 9) return 0;
    return tmp;
}

bool compare(string &a, string &b) {
    if (a.length() == b.length()) {
        // 자리수 합 계산
        int aSum = 0, bSum = 0;
        for (int i = 0; i < a.length(); i++) {
            aSum += ctoi(a[i]);
            bSum += ctoi(b[i]);
        }
        // 차례대로 3번조건(사전순), 2번조건(자리합순)
        return (aSum == bSum ? a < b : aSum < bSum);
    }
    // 1번 조건
    return a.length() < b.length();
}

int main() {
    int N; std::cin >> N;
    std::vector<string> guitars(N);
    for (int i = 0; i < N; i++) std::cin >> guitars[i];
    std::sort(guitars.begin(), guitars.end(), compare);
    for (string guitar : guitars) std::cout << guitar << '\n';
}
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string str1, str2, str3;
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());
	str3 = to_string(stoi(str1) + stoi(str2));
	reverse(str3.begin(), str3.end());
	cout << stoi(str3);
}
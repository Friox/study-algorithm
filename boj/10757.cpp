#include <iostream>
#include <string>
using namespace std;

void solve(string a, string b) {
	int n1[10001], n2[10001], r[10001], c = 0, base;
	int len1, len2, endPoint;
	fill_n(n1, 10001, 0);
	fill_n(n2, 10001, 0);
	fill_n(r, 10001, 0);
	len1 = a.length();
	len2 = b.length();
	endPoint = 10000 - (len1 > len2 ? len1 : len2);
	for (int i = len1 - 1, t = 10000; i >= 0; i--, t--) n1[t] = a[i] - 48;
	for (int i = len2 - 1, t = 10000; i >= 0; i--, t--) n2[t] = b[i] - 48;
	for (int i = 10000; i >= endPoint; i--) {
		base = c + n1[i] + n2[i];
		r[i] = base % 10;
		c = base / 10;
	}
	for (int i = endPoint; i <= 10000; i++) {
		if (i == endPoint && !r[i]) continue;
		cout << r[i];
	}
	cout << '\n';
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	solve(s1, s2);
}
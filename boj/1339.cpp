#include <iostream>
#include <algorithm>
using namespace std;
int w[26], sum;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	string str[10];
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> str[i];
		for (int j = str[i].length() - 1, k = 1; j >= 0; --j, k *= 10) w[str[i][j] - 'A'] += k;
	}
	sort(w, w + 26);
	for (int i = 25, j = 9; i >= 16; --i, --j) {
		if (!w[i]) break;
		sum += w[i] * j;
	}
	cout << sum;
}
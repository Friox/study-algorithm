#include <stdio.h>
#include <stack>
char str[100001];
int main() {
	int res = 0;
	scanf("%s", str);
	std::stack<char> tmp;
	for (int i = 0; str[i] != 0; ++i) {
		if (str[i] == '(') tmp.push(str[i]);
		else {
			tmp.pop();
			if (str[i - 1] == '(') res += tmp.size();
			else ++res;
		}
	}
	printf("%d", res);
}
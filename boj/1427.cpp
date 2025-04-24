#include <stdio.h>
#include <algorithm>

bool compare(char a, char b) {
	if (a < b) return false;
	else return true;
}

int main() {
	char str[11] = { 0 };
	scanf("%s", str);
	std::sort(str, str + 11, compare);
	printf("%s", str);
}
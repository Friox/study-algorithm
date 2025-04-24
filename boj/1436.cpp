#include <stdio.h>
#include <string>

int main() {
	int n, i = 665, cnt = 0;
	scanf("%d", &n);
	do {
		i++;
		if (std::to_string(i).find("666") != std::string::npos) cnt++;
	} while (cnt != n);
	printf("%d", i);
}
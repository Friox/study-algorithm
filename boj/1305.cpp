#include <stdio.h>
char str[1000001];
int pi[1000001];
int main() {
	int n, a = 0;
	scanf("%d %s", &n, str);
    for (int i = 1; i < n; ++i){
        while (a && str[i] != str[a]) a = pi[a - 1];
        if (str[i] == str[a]) pi[i] = ++a;
    }
	printf("%d", n - pi[n - 1]);
}
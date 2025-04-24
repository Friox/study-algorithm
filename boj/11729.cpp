#include <ios>

void hanoi(int f, int v, int t, int n) {
	if (n == 1) printf("%d %d\n", f, t);
	else {
		hanoi(f, t, v, n - 1);
		printf("%d %d\n", f, t);
		hanoi(v, f, t, n - 1);
	}
}

int main() {
	int n, t = 1;
	scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) t = t * 2 + 1;
	printf("%d\n", t);
	hanoi(1, 2, 3, n);
}